let originalContestData = []; // 元のコンテストデータを保持
let contestData = [];        // 表示用データ

async function loadData() {
    try {
        const response = await fetch('/CompetitiveProgramming/js/user.json');
        const data = await response.json();
        return data.map(entry => ({
            contest: entry.contest,
            performance: entry.performance,
            rating: entry.rating
        }));
    } catch (error) {
        console.error('Error loading data:', error);
        return [];
    }
}

async function displayContestData() {
    // 初回のみ元データをロード
    if (originalContestData.length === 0) {
        originalContestData = await loadData();
    }
    contestData = [...originalContestData]; // 元データをコピー
    renderTable();
}


function calculateRatings(data, originalLength) {
    const performances = data.map(entry => entry.performance);

    return data.map((entry, index) => {
        if (index < originalLength) {
            return entry; // 元のデータはそのまま
        }

        // 1回目からその回までのパフォーマンスを使って rating を計算
        const currentPerformances = performances.slice(0, index + 1);
        const rating = calcRating(currentPerformances);

        return {
            ...entry,
            rating: rating
        };
    });
}

function addPerformances() {
    const input = document.getElementById('performanceInput').value;
    contestData = [...originalContestData];
    const originalLength = contestData.length;

    const performances = input.split('\n')
        .map(p => p.trim())
        .filter(p => p && !isNaN(p));

    performances.forEach(performance => {
        contestData.push({
            contest: `Dummy Contest ${contestData.length + 1}`,
            performance: parseInt(performance),
            rating: '-'
        });
    });

    contestData = calculateRatings(contestData, originalLength);
    renderTable();
}


function renderTable() {
    if (contestData) {
        contestData = contestData.slice().reverse();
        const table = document.createElement('table');
        table.border = '1';

        // ヘッダー行の作成
        const thead = document.createElement('thead');
        const headerRow = document.createElement('tr');
        ['Contest', 'Performance', 'Rating'].forEach(headerText => {
            const th = document.createElement('th');
            th.textContent = headerText;
            headerRow.appendChild(th);
        });
        thead.appendChild(headerRow);
        table.appendChild(thead);

        // データ行の作成
        const tbody = document.createElement('tbody');
        contestData.forEach(data => {
            const row = document.createElement('tr');
            [data.contest, data.performance, data.rating].forEach(cellData => {
                const td = document.createElement('td');
                td.textContent = cellData;
                row.appendChild(td);
            });
            tbody.appendChild(row);
        });
        table.appendChild(tbody);

        document.getElementById('result').innerHTML = '';
        document.getElementById('result').appendChild(table);
    }
}

// queted from 3w36zj6/atcoder-rating-estimator
// https://github.com/3w36zj6/atcoder-rating-estimator/blob/f55ccd63b7e8fa55d89cb44abd19ea04153be11e/LICENSE
// https://github.com/3w36zj6/atcoder-rating-estimator/blob/f55ccd63b7e8fa55d89cb44abd19ea04153be11e/src/lib/calculateRating.ts
function applyRatingCorrection(rating) {
    if (rating<400) {
        return 400 / Math.exp((400 - rating) / 400);
    }
    return rating;
}

function calcRating(arr) {
    if (arr.length === 0) {
        throw new Error('Empty array');
    }

    const f = (n) => {
        const F = (n) => {
            let numerator = 0;
            let denominator = 0;
            for (let i = 0; i < n; i++) {
                numerator += Math.pow(0.81, i);
                denominator += Math.pow(0.9, i);
            }
            return Math.sqrt(numerator) / denominator;
        };
        const FInf = Math.sqrt(0.81 / (1 - 0.81)) / (0.9 / (1 - 0.9));
		return ((F(n) - FInf) / (F(1) - FInf)) * 1200;
    };
    const g = (x) => Math.pow(2, x / 800);
	const gInv = (y) => 800 * Math.log2(y);

	let weightedGSum = 0;
	let weightSum = 0;
	const performances = arr.slice().reverse();
	for (let i = 0; i < performances.length; i++) {
		const weight = Math.pow(0.9, i);
		weightedGSum += g(performances[i]) * weight;
		weightSum += weight;
	}

	let rating = gInv(weightedGSum / weightSum) - f(performances.length);
	rating = applyRatingCorrection(rating);
	return Math.round(rating);
};

window.displayContestData = displayContestData;
window.addPerformances = addPerformances;
document.addEventListener('DOMContentLoaded', displayContestData);
