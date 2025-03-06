async function loadData() {
    try {
        const response = await fetch('/CompetitiveProgramming/js/stat.json');
        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error loading data:', error);
        return {};
    }
}


let displayCount = 100; // Default display count

document.getElementById('displayCountSlider').addEventListener('input', function(event) {
    displayCount = event.target.value;
    document.getElementById('displayCountTextBox').value = displayCount;
    updateDisplay();
});

document.getElementById('displayCountTextBox').addEventListener('change', function(event) {
    displayCount = event.target.value;
    document.getElementById('displayCountSlider').value = displayCount;
    updateDisplay();
});


function updateDisplay() {
    loadData().then(data => {
        const dates = Object.keys(data).sort();
        const colors = [
            { name: "gray", color: "#808080" },
            { name: "brown", color: "#A52A2A" },
            { name: "green", color: "#008000" },
            { name: "cyan", color: "#00FFFF" },
            { name: "blue", color: "#0000FF" },
            { name: "yellow", color: "#FFFF00" },
            { name: "orange", color: "#FFA500" },
            { name: "red", color: "#FF0000" }
        ];

        const parseDate = d3.timeParse("%Y%m%d");
        const formattedDates = dates.map(date => parseDate(date));

        const traces = colors.map(color => ({
            x: formattedDates.slice(-displayCount),
            y: dates.map(date => data[date][color.name]).slice(-displayCount),
            mode: 'lines+markers',
            type: 'scatter',
            name: color.name,
            line: { color: color.color },
            marker: { color: color.color }
        }));

        const layout = {
            title: {
                text: 'submissions'
            },
            xaxis: {
                title: 'Date',
                type: 'date'
            },
            yaxis: {
                title: 'Count'
            }
        };

        Plotly.newPlot('submissions', traces, layout);
    });
}

updateDisplay();
