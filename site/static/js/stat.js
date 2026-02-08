async function loadRatingData() {
	try {
		const response = await fetch("/CompetitiveProgramming/js/goropikari.json");
		const data = await response.json();
		return data;
	} catch (error) {
		console.error("Error loading data:", error);
		return {};
	}
}

function displayRating() {
	loadRatingData().then((data) => {
		const filteredData = data.filter((entry) => entry.IsRated);
		const ratings = filteredData.map((entry) => entry.NewRating);
		const dates = filteredData.map((entry) => new Date(entry.EndTime));
		const colors = filteredData.map((entry) => {
			if (entry.NewRating < 400)
				return "#808080"; // gray
			else if (entry.NewRating < 800)
				return "#A52A2A"; // brown
			else if (entry.NewRating < 1200)
				return "#008000"; // green
			else if (entry.NewRating < 1600)
				return "#00FFFF"; // cyan
			else if (entry.NewRating < 2000)
				return "#0000FF"; // blue
			else if (entry.NewRating < 2400)
				return "#FFFF00"; // yellow
			else if (entry.NewRating < 2800)
				return "#FFA500"; // orange
			else return "#FF0000"; // red
		});
		const contestNames = filteredData.map((entry) => entry.ContestName);

		const trace = {
			x: dates,
			y: ratings,
			text: contestNames,
			mode: "lines+markers",
			type: "scatter",
			name: "Rating",
			line: { color: "#808080" },
			marker: { color: colors },
			hovertemplate: "Date: %{x}<br>Rating: %{y}<br>%{text}<extra></extra>",
		};

		const layout = {
			title: {
				text: "User Rating Over Time",
			},
			xaxis: {
				title: "Date",
				type: "date",
			},
			yaxis: {
				title: "Rating",
			},
		};

		Plotly.newPlot("rating", [trace], layout);
	});
}

let displayCount = 100; // Default display count

function updateDisplay() {
	loadData().then((data) => {
		const dates = Object.keys(data).sort();
		const colors = [
			{ name: "gray", color: "#808080" },
			{ name: "brown", color: "#A52A2A" },
			{ name: "green", color: "#008000" },
			{ name: "cyan", color: "#00FFFF" },
			{ name: "blue", color: "#0000FF" },
			{ name: "yellow", color: "#FFFF00" },
			{ name: "orange", color: "#FFA500" },
			{ name: "red", color: "#FF0000" },
		];

		const parseDate = d3.timeParse("%Y%m%d");
		const formattedDates = dates.map((date) => parseDate(date));

		const traces = colors.map((color) => ({
			x: formattedDates.slice(-displayCount),
			y: dates.map((date) => data[date][color.name]).slice(-displayCount),
			mode: "lines+markers",
			type: "scatter",
			name: color.name,
			line: { color: color.color },
			marker: { color: color.color },
		}));

		const layout = {
			title: {
				text: "submissions",
			},
			xaxis: {
				title: "Date",
				type: "date",
			},
			yaxis: {
				title: "Count",
			},
		};

		Plotly.newPlot("submissions", traces, layout);
	});
}

[
	{ IsRated: true, EndTime: "2023-01-15T12:00:00Z", NewRating: 1500 },
	{ IsRated: false, EndTime: "2023-02-15T12:00:00Z", NewRating: 1550 },
	{ IsRated: true, EndTime: "2023-02-15T12:00:00Z", NewRating: 1550 },
];
