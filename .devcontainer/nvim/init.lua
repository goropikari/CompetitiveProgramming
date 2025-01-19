vim.g.mapleader = ","
vim.g.maplocalleader = ","
vim.wo.number = true
vim.wo.signcolumn = "yes"
vim.o.expandtab = true
vim.o.tabstop = 4
vim.o.shiftwidth = 4

-- clipboard
vim.opt.clipboard = "unnamedplus" -- Sync with system clipboard

-- https://neovim.io/doc/user/provider.html#clipboard-osc52
vim.g.clipboard = {
	name = "OSC 52",
	copy = {
		["+"] = require("vim.ui.clipboard.osc52").copy("+"),
	},
	paste = {
		-- https://github.com/neovim/neovim/discussions/28010#discussioncomment-9877494
		["+"] = function()
			return {
				vim.fn.split(vim.fn.getreg(""), "\n"),
				vim.fn.getregtype(""),
			}
		end,
	},
}

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not (vim.uv or vim.loop).fs_stat(lazypath) then
	local lazyrepo = "https://github.com/folke/lazy.nvim.git"
	local out = vim.fn.system({ "git", "clone", "--filter=blob:none", "--branch=stable", lazyrepo, lazypath })
	if vim.v.shell_error ~= 0 then
		vim.api.nvim_echo({
			{ "Failed to clone lazy.nvim:\n", "ErrorMsg" },
			{ out, "WarningMsg" },
			{ "\nPress any key to exit..." },
		}, true, {})
		vim.fn.getchar()
		os.exit(1)
	end
end
vim.opt.rtp:prepend(lazypath)

-- Setup lazy.nvim
require("lazy").setup({
	spec = {
		{
			"neanias/everforest-nvim",
			version = false,
			lazy = false,
			priority = 1000, -- make sure to load this before all the other start plugins
			-- Optional; default configuration will be used if setup isn't called.
			config = function()
				require("everforest").setup({})
				vim.cmd([[colorscheme everforest]])
			end,
		},
		{
			-- Autocompletion
			"hrsh7th/nvim-cmp",
			event = "InsertEnter",
			dependencies = {
				-- Snippet Engine & its associated nvim-cmp source
				{
					"L3MON4D3/LuaSnip",
					build = (function()
						-- Build Step is needed for regex support in snippets
						-- This step is not supported in many windows environments
						-- Remove the below condition to re-enable on windows
						if vim.fn.has("win32") == 1 then
							return
						end
						return "make install_jsregexp"
					end)(),
				},
				"saadparwaiz1/cmp_luasnip",

				-- Adds LSP completion capabilities
				"hrsh7th/cmp-nvim-lsp",
				"hrsh7th/cmp-path",

				-- Adds a number of user-friendly snippets
				"rafamadriz/friendly-snippets",

				-- neovim lua
				{
					"folke/lazydev.nvim",
					ft = "lua", -- only load on lua files
					opts = {
						library = {
							-- See the configuration section for more details
							-- Load luvit types when the `vim.uv` word is found
							{ path = "luvit-meta/library", words = { "vim%.uv" } },
						},
					},
				},
				{ "Bilal2453/luvit-meta", lazy = true }, -- optional `vim.uv` typings
			},
			config = function()
				local cmp = require("cmp")
				local luasnip = require("luasnip")
				-- require('luasnip.loaders.from_vscode').lazy_load()
				-- luasnip.config.setup({})

				cmp.setup({
					snippet = {
						expand = function(args)
							luasnip.lsp_expand(args.body)
						end,
					},
					completion = {
						completeopt = "menu,menuone,noinsert",
					},
					mapping = cmp.mapping.preset.insert({
						["<C-n>"] = cmp.mapping.select_next_item(),
						-- ['<C-p>'] = cmp.mapping.select_prev_item(),
						-- ['<C-b>'] = cmp.mapping.scroll_docs(-4),
						-- ['<C-f>'] = cmp.mapping.scroll_docs(4),
						-- ['<C-Space>'] = cmp.mapping.complete {},
						["<CR>"] = cmp.mapping.confirm({
							behavior = cmp.ConfirmBehavior.Replace,
							select = true,
						}),
						-- ['<Tab>'] = cmp.mapping(function(fallback)
						--   if cmp.visible() then
						--     cmp.select_next_item()
						--   elseif luasnip.expand_or_locally_jumpable() then
						--     luasnip.expand_or_jump()
						--   else
						--     fallback()
						--   end
						-- end, { 'i', 's' }),
						-- ['<S-Tab>'] = cmp.mapping(function(fallback)
						--   if cmp.visible() then
						--     cmp.select_prev_item()
						--   elseif luasnip.locally_jumpable(-1) then
						--     luasnip.jump(-1)
						--   else
						--     fallback()
						--   end
						-- end, { 'i', 's' }),
					}),
					sources = {
						{ name = "nvim_lsp" },
						{ name = "luasnip" },
						{ name = "path" },
						{
							name = "lazydev",
							group_index = 0, -- set group index to 0 to skip loading LuaLS completions
						},
					},
				})
			end,
		},
		{
			-- Autoformat
			"stevearc/conform.nvim",
			event = { "BufWritePre" },
			opts = {
				notify_on_error = false,
				format_on_save = function(bufnr)
					-- Disable "format_on_save lsp_fallback" for languages that don't
					-- have a well standardized coding style. You can add additional
					-- languages here or re-enable it for the disabled ones.
					local disable_filetypes = { c = false, cpp = false, html = true }
					local lsp_format_opt
					if disable_filetypes[vim.bo[bufnr].filetype] then
						lsp_format_opt = "never"
					else
						lsp_format_opt = "fallback"
					end
					return {
						timeout_ms = 500,
						lsp_format = lsp_format_opt,
					}
				end,
			},
		},
		{
			"mfussenegger/nvim-dap",
			version = "0.8.0",
			dependencies = {
				{
					-- Creates a beautiful debugger UI
					"rcarriga/nvim-dap-ui",
					dependencies = { "nvim-neotest/nvim-nio" },
					config = function()
						local dap = require("dap")
						local dapui = require("dapui")
						dapui.setup()
						dap.listeners.after.event_initialized["dapui_config"] = dapui.open
						dap.listeners.before.event_terminated["dapui_config"] = dapui.close
						dap.listeners.before.event_exited["dapui_config"] = dapui.close
					end,
				},
				{
					-- code 中に変数の値を表示する
					"theHamsta/nvim-dap-virtual-text",
					opts = {},
				},
			},
			keys = {
				{ "<leader>d", desc = "Debug" },
				{
					"<leader>dC",
					function()
						require("dap").clear_breakpoints()
					end,
					desc = "Debug: Clear Breakpoint",
				},
				{
					"<leader>db",
					function()
						require("dap").toggle_breakpoint()
					end,
					desc = "Debug: Toggle Breakpoint",
				},
				{
					"<leader>dc",
					function()
						require("dap").toggle_breakpoint(vim.fn.input("debug condition: "))
					end,
					desc = "Debug: Toggle Conditional Breakpoint",
				},
				{
					"<leader>duc",
					function()
						require("dapui").close()
					end,
					desc = "Close DAP UI",
				},
				{
					"<F5>",
					function()
						require("dap").continue()
					end,
					desc = "Debug: Continue",
				},
				{
					"<F10>",
					function()
						require("dap").step_over()
					end,
					desc = "Debug: Step over",
				},
			},
		},
		{
			"mfussenegger/nvim-dap-python",
			ft = { "python" },
			config = function()
				require("dap-python").setup("python3")
			end,
		},
		{
			"nvim-treesitter/nvim-treesitter",
			dependencies = {
				"nvim-treesitter/nvim-treesitter-textobjects",
			},
			build = ":TSUpdate",
			config = function()
				vim.defer_fn(function()
					require("nvim-treesitter.configs").setup({
						ensure_installed = { "cpp", "python" },
					})
				end, 0)
			end,
		},
		{
			-- LSP Configuration & Plugins
			"neovim/nvim-lspconfig",
			dependencies = {
				-- Automatically install LSPs and related tools to stdpath for Neovim
				{ "williamboman/mason.nvim", config = true }, -- NOTE: Must be loaded before dependants
				"williamboman/mason-lspconfig.nvim",

				-- -- Useful status updates for LSP.
				-- { 'j-hui/fidget.nvim', opts = {} },

				-- Allows extra capabilities provided by nvim-cmp
				"hrsh7th/cmp-nvim-lsp",
			},
			config = function()
				vim.api.nvim_create_autocmd("LspAttach", {
					group = vim.api.nvim_create_augroup("kickstart-lsp-attach", { clear = true }),
					callback = function(event)
						-- NOTE: Remember that Lua is a real programming language, and as such it is possible
						-- to define small helper and utility functions so you don't have to repeat yourself.
						--
						-- In this case, we create a function that lets us more easily define mappings specific
						-- for LSP related items. It sets the mode, buffer and description for us each time.
						local map = function(keys, func, desc, mode)
							mode = mode or "n"
							vim.keymap.set(mode, keys, func, { buffer = event.buf, desc = "LSP: " .. desc })
						end

						-- Jump to the definition of the word under your cursor.
						--  This is where a variable was first declared, or where a function is defined, etc.
						--  To jump back, press <C-t>.
						map("gd", require("telescope.builtin").lsp_definitions, "Goto Definition")

						-- Find references for the word under your cursor.
						map("gr", require("telescope.builtin").lsp_references, "Goto References")

						-- Jump to the implementation of the word under your cursor.
						--  Useful when your language has ways of declaring types without an actual implementation.
						map("gI", require("telescope.builtin").lsp_implementations, "Goto Implementation")

						-- Jump to the type of the word under your cursor.
						--  Useful when you're not sure what type a variable is and you want to see
						--  the definition of its *type*, not where it was *defined*.
						map("<leader>lD", require("telescope.builtin").lsp_type_definitions, "Type Definition")

						-- Fuzzy find all the symbols in your current document.
						--  Symbols are things like variables, functions, types, etc.
						map("<leader>lds", require("telescope.builtin").lsp_document_symbols, "Document Symbols")

						-- Fuzzy find all the symbols in your current workspace.
						--  Similar to document symbols, except searches over your entire project.
						map(
							"<leader>lws",
							require("telescope.builtin").lsp_dynamic_workspace_symbols,
							"Workspace Symbols"
						)

						-- Rename the variable under your cursor.
						--  Most Language Servers support renaming across files, etc.
						map("<leader>lrn", vim.lsp.buf.rename, "Rename")
						map("<F2>", vim.lsp.buf.rename, "Rename")

						-- Execute a code action, usually your cursor needs to be on top of an error
						-- or a suggestion from your LSP for this to activate.
						-- map('<leader>lca', vim.lsp.buf.code_action, 'Code Action', { 'n', 'x' })
						map("<leader>lca", function()
							vim.lsp.buf.code_action({
								context = { diagnostics = {}, only = { "quickfix", "refactor", "source" } },
								apply = true,
							})
						end, "Code Action", { "n", "x" })

						-- WARN: This is not Goto Definition, this is Goto Declaration.
						--  For example, in C this would take you to the header.
						map("gD", vim.lsp.buf.declaration, "Goto Declaration")

						map("<leader>lK", vim.lsp.buf.hover, "Hover Documentation")
						map("<leader>ldh", vim.lsp.buf.hover, "Hover Documentation")
						map("<leader>lf", function(_)
							vim.lsp.buf.format()
						end, "Format")
						map("<leader>lgD", vim.lsp.buf.declaration, "Goto Declaration")
						map("<leader>lgI", require("telescope.builtin").lsp_implementations, "Goto Implementation")
						map("<leader>lgd", require("telescope.builtin").lsp_definitions, "Goto Definition")
						map("<leader>lgr", require("telescope.builtin").lsp_references, "Goto References")
						map("<leader>lk", vim.lsp.buf.signature_help, "Signature Documentation")

						-- The following two autocommands are used to highlight references of the
						-- word under your cursor when your cursor rests there for a little while.
						--    See `:help CursorHold` for information about when this is executed
						--
						-- When you move your cursor, the highlights will be cleared (the second autocommand).
						local client = vim.lsp.get_client_by_id(event.data.client_id)
						if
							client and client.supports_method(vim.lsp.protocol.Methods.textDocument_documentHighlight)
						then
							local highlight_augroup =
								vim.api.nvim_create_augroup("kickstart-lsp-highlight", { clear = false })
							vim.api.nvim_create_autocmd({ "CursorHold", "CursorHoldI" }, {
								buffer = event.buf,
								group = highlight_augroup,
								callback = vim.lsp.buf.document_highlight,
							})

							vim.api.nvim_create_autocmd({ "CursorMoved", "CursorMovedI" }, {
								buffer = event.buf,
								group = highlight_augroup,
								callback = vim.lsp.buf.clear_references,
							})

							vim.api.nvim_create_autocmd("LspDetach", {
								group = vim.api.nvim_create_augroup("kickstart-lsp-detach", { clear = true }),
								callback = function(event2)
									vim.lsp.buf.clear_references()
									vim.api.nvim_clear_autocmds({
										group = "kickstart-lsp-highlight",
										buffer = event2.buf,
									})
								end,
							})
						end

						-- The following code creates a keymap to toggle inlay hints in your
						-- code, if the language server you are using supports them
						--
						-- This may be unwanted, since they displace some of your code
						if client and client.supports_method(vim.lsp.protocol.Methods.textDocument_inlayHint) then
							map("<leader>lth", function()
								vim.lsp.inlay_hint.enable(not vim.lsp.inlay_hint.is_enabled({ bufnr = event.buf }))
							end, "Toggle Inlay Hints")
						end
					end,
				})

				-- LSP servers and clients are able to communicate to each other what features they support.
				--  By default, Neovim doesn't support everything that is in the LSP specification.
				--  When you add nvim-cmp, luasnip, etc. Neovim now has *more* capabilities.
				--  So, we create new capabilities with nvim cmp, and then broadcast that to the servers.
				local capabilities = vim.lsp.protocol.make_client_capabilities()
				capabilities =
					vim.tbl_deep_extend("force", capabilities, require("cmp_nvim_lsp").default_capabilities())

				-- Enable the following language servers
				--  Feel free to add/remove any LSPs that you want here. They will automatically be installed.
				--
				--  Add any additional override configuration in the following tables. Available keys are:
				--  - cmd (table): Override the default command used to start the server
				--  - filetypes (table): Override the default list of associated filetypes for the server
				--  - capabilities (table): Override fields in capabilities. Can be used to disable certain LSP features.
				--  - settings (table): Override the default settings passed when initializing the server.
				--        For example, to see the options for `lua_ls`, you could go to: https://luals.github.io/wiki/settings/
				local lsp_servers = {
					-- html = { filetypes = { 'html', 'twig', 'hbs' } },
					typos_lsp = {},
					lua_ls = {
						-- cmd = {...},
						-- filetypes = { ...},
						-- capabilities = {},
						settings = {
							-- https://github.com/LuaLS/lua-language-server/blob/cb964c600570e6258d3c0a3f3f424a35a3a4ef64/doc/en-us/config.md
							Lua = {
								completion = {
									callSnippet = "Replace",
								},
								-- You can toggle below to ignore Lua_LS's noisy `missing-fields` warnings
								-- diagnostics = { disable = { 'missing-fields' } },
							},
						},
					},
					jsonls = {},
					biome = {},
				}

				for executable, config in pairs({
					-- executable = {lsp = config}
					go = {
						gopls = {
							settings = {
								gopls = {
									gofumpt = true,
									codelenses = {
										gc_details = false,
										generate = true,
										regenerate_cgo = true,
										run_govulncheck = true,
										test = true,
										tidy = true,
										upgrade_dependency = true,
										vendor = true,
									},
									hints = {
										assignVariableTypes = true,
										compositeLiteralFields = true,
										compositeLiteralTypes = true,
										constantValues = true,
										functionTypeParameters = true,
										parameterNames = true,
										rangeVariableTypes = true,
									},
									analyses = {
										fieldalignment = false,
										nilness = true,
										unusedparams = true,
										unusedwrite = true,
										useany = true,
									},
									usePlaceholders = true,
									completeUnimported = true,
									staticcheck = true,
									directoryFilters = {
										"-.git",
										"-.vscode",
										"-.idea",
										"-.vscode-test",
										"-node_modules",
									},
									semanticTokens = true,
								},
							},
						},
					},
					ruby = {
						ruby_lsp = {},
					},
					clangd = {
						clangd = {
							-- https://www.reddit.com/r/neovim/comments/16qwp3d/comment/k261adn/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
							cmd = {
								"clangd",
								"--fallback-style=webkit",
							},
						},
					},
				}) do
					if vim.fn.executable(executable) == 1 then
						for key, val in pairs(config) do
							lsp_servers[key] = val
						end
					end
				end

				require("mason").setup()
				require("mason-lspconfig").setup({
					handlers = {
						function(server_name)
							local server = lsp_servers[server_name] or {}
							-- This handles overriding only values explicitly passed
							-- by the server configuration above. Useful when disabling
							-- certain features of an LSP (for example, turning off formatting for ts_ls)

							server.capabilities =
								vim.tbl_deep_extend("force", {}, capabilities, server.capabilities or {})
							require("lspconfig")[server_name].setup(server)
						end,
					},
				})

				-- diagnostics の出所と理由を表示するようにする
				-- https://dev.classmethod.jp/articles/eetann-change-neovim-lsp-diagnostics-format/
				vim.lsp.handlers["textDocument/publishDiagnostics"] =
					vim.lsp.with(vim.lsp.diagnostic.on_publish_diagnostics, {
						update_in_insert = false,
						virtual_text = {
							spacing = 0,
							suffix = function(diagnostic)
								-- print(vim.inspect(diagnostic))
								return string.format(" (%s: %s)", diagnostic.source, diagnostic.code)
							end,
						},
					})
			end,
		},
		{
			"WhoIsSethDaniel/mason-tool-installer.nvim",
			opts = {
				ensure_installed = {
					"clangd",
					"codelldb",
					"lua_ls",
					"typos_lsp",
				},
			},
		},
		{
			-- Fuzzy Finder (files, lsp, etc)
			"nvim-telescope/telescope.nvim",
			event = "VeryLazy",
			branch = "0.1.x",
			dependencies = {
				"folke/which-key.nvim",
				"nvim-lua/plenary.nvim",
				-- Fuzzy Finder Algorithm which requires local dependencies to be built.
				-- Only load if `make` is available. Make sure you have the system
				-- requirements installed.
				{
					"nvim-telescope/telescope-fzf-native.nvim",
					-- NOTE: If you are having trouble with this installation,
					--       refer to the README for telescope-fzf-native for more instructions.
					build = "make",
					cond = function()
						return vim.fn.executable("make") == 1
					end,
				},
			},
			config = function()
				-- local actions = require('telescope.actions')
				require("telescope").setup({
					-- defaults = {
					--   mappings = {
					--     i = {
					--       ['<c-CR>'] = actions.select_default,
					--       ['<CR>'] = actions.nop,
					--     },
					--     n = {
					--       ['<c-CR>'] = actions.select_default,
					--       ['<CR>'] = actions.nop,
					--     },
					--   },
					-- },
				})

				-- Enable telescope fzf native, if installed
				pcall(require("telescope").load_extension, "fzf")
			end,
			keys = {
				{
					"<leader>?",
					function()
						require("telescope.builtin").oldfiles()
					end,
					desc = "[?] Find recently opened files",
				},
				{
					"<leader><space>",
					function()
						require("telescope.builtin").buffers()
					end,
					desc = "[ ] Find existing buffers",
				},
				{
					"<leader>/",
					function()
						-- You can pass additional configuration to telescope to change theme, layout, etc.
						require("telescope.builtin").current_buffer_fuzzy_find(
							require("telescope.themes").get_dropdown({
								winblend = 10,
								previewer = false,
							})
						)
					end,
					desc = "[/] Fuzzily search in current buffer",
				},
				{
					"<leader>p",
					function()
						require("telescope.builtin").find_files({ hidden = true, file_ignore_patterns = { ".git/" } })
					end,
					desc = "search file",
				},
				{
					"<leader>sb",
					function()
						require("telescope.builtin").current_buffer_fuzzy_find()
					end,
					desc = "Search current Buffer",
				},
				{
					"<leader>ss",
					function()
						require("telescope.builtin").builtin()
					end,
					desc = "Search Select Telescope",
				},
				{
					"<leader>gf",
					function()
						require("telescope.builtin").git_files()
					end,
					desc = "Search Git Files",
				},
				{
					"<leader>gs",
					function()
						require("telescope.builtin").git_status()
					end,
					desc = "Search Git Status",
				},
				{
					"<leader>sf",
					function()
						require("telescope.builtin").find_files()
					end,
					desc = "Search Files",
				},
				{
					"<leader>sh",
					function()
						require("telescope.builtin").help_tags()
					end,
					desc = "Search Help",
				},
				{
					"<leader>sw",
					function()
						require("telescope.builtin").grep_string()
					end,
					desc = "Search current Word",
				},
				{
					"<leader>sg",
					function()
						require("telescope.builtin").live_grep()
					end,
					desc = "Search by Grep",
				},
				-- {
				--   '<leader>sd',
				--   function()
				--     require('telescope.builtin').diagnostics()
				--   end,
				--   desc = 'Search Diagnostics',
				-- },
				{
					-- zenn or hugo article list
					"<leader>zz",
					function()
						if vim.uv.fs_stat("content") then
							require("telescope").extensions.hugo.hugo()
						elseif vim.uv.fs_stat("articles") then
							require("telescope").extensions.zenn.zenn()
						end
					end,
					desc = "search article",
				},
			},
		},
		{
			-- sidebar file explorer
			"nvim-neo-tree/neo-tree.nvim",
			branch = "v3.x",
			-- cmd = 'Neotree',
			dependencies = {
				"nvim-lua/plenary.nvim",
				"nvim-tree/nvim-web-devicons", -- not strictly required, but recommended
				"MunifTanjim/nui.nvim",
				-- "3rd/image.nvim", -- Optional image support in preview window: See `# Preview Mode` for more information
			},
			keys = {
				{
					"<c-e>", -- Ctrl-e で neo-tree の表示切り替え
					function()
						require("neo-tree.command").execute({ toggle = true })
					end,
					desc = "Explorer NeoTree",
				},
			},
			deactivate = function()
				vim.cmd([[Neotree close]])
			end,
			init = function()
				if vim.fn.argc(-1) == 1 then
					local stat = vim.loop.fs_stat(vim.fn.argv(0))
					if stat and stat.type == "directory" then
						require("neo-tree")
					end
				end
			end,
			opts = {
				sources = { "filesystem", "buffers", "git_status", "document_symbols" },
				open_files_do_not_replace_types = { "terminal", "Trouble", "trouble", "qf", "Outline" },
				hijack_netrw_behavior = "disabled",
				filesystem = {
					bind_to_cwd = false,
					follow_current_file = { enabled = true },
					use_libuv_file_watcher = true,
					filtered_items = {
						hide_dotfiles = false,
					},
				},
				window = {
					position = "float",
					mappings = {
						["<space>"] = "none",
						["Y"] = function(state)
							local node = state.tree:get_node()
							local path = node:get_id()
							vim.fn.setreg("+", path, "c")
						end,
					},
				},
				default_component_configs = {
					indent = {
						with_expanders = true, -- if nil and file nesting is enabled, will enable expanders
						expander_collapsed = "",
						expander_expanded = "",
						expander_highlight = "NeoTreeExpander",
					},
				},
			},
		},
		{
			"goropikari/online-judge.nvim",
			opts = {
				oj = {
					path = (function()
						if vim.fn.executable("oj") == 1 then
							return "oj"
						end
						local oj_venv = vim.fn.fnamemodify("~/venv/bin/oj", ":p")
						if vim.fn.executable(oj_venv) == 1 then
							return oj_venv
						end
					end)(),
				},
			},
			keys = {
				{
					"<leader>at",
					function()
						require("online-judge").test()
					end,
					desc = "online-judge test",
				},
				{
					"<leader>ai",
					function()
						require("online-judge").insert_problem_url()
						vim.api.nvim_buf_set_lines(
							0,
							1,
							1,
							false,
							{ string.format(vim.bo.commentstring, vim.fn.strftime("%c")) }
						)
					end,
					desc = "insert atcoder url",
				},
				{
					"<leader>acd",
					function()
						require("online-judge").create_test_dir()
					end,
					desc = "create test directory for non supported site",
				},
			},
		},
	},
	checker = {
		-- automatically check for plugin updates
		enabled = true,
		concurrency = nil, ---@type number? set to 1 to check for updates very slowly
		notify = false, -- get a notification when new updates are found
		frequency = 3600, -- check for updates every hour
		check_pinned = false, -- check for pinned packages that can't be updated
	},
	change_detection = {
		-- automatically check for config file changes and reload the ui
		enabled = true,
		notify = false, -- get a notification when changes are found
	},
	performance = {
		cache = {
			enabled = true,
		},
		reset_packpath = true, -- reset the package path to improve startup time
		rtp = {
			disabled_plugins = {
				-- https://github.com/neovim/neovim/tree/43d552c56648bc3125c7509b3d708b6bf6c0c09c/runtime/plugin
				"gzip",
				"man", -- man page
				"netrw",
				"netrwPlugin",
				"netrwSettings",
				"rplugin", -- remote plugin
				"tarPlugin",
				"tohtml",
				"tutor",
				"zipPlugin", -- "netrwFileHandlers",
			},
		},
	},
})
