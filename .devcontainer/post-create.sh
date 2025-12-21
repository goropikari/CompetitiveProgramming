cd ~
python3 -m venv venv
source venv/bin/activate
echo "source ~/venv/bin/activate" >> ~/.bashrc
echo 'eval "$(direnv hook bash)"' >> ~/.bashrc

pipx install git+https://github.com/goropikari/oj@main
