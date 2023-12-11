const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter a year (1-9999): ', (yearInput) => {
  const year = parseInt(yearInput);

  if (year < 1 || year > 9999 || isNaN(year)) {
    console.log('Please choose another year within the range.');
    rl.close();
  } else {
    for (let month = 0; month < 12; month++) {
      const currentDate = new Date(year, month, 1);
      const monthName = currentDate.toLocaleString('default', { month: 'long' });
      const daysInMonth = new Date(year, month + 1, 0).getDate();
      const firstDay = new Date(year, month, 1).getDay();

      console.log(`\n${monthName} ${year}`);
      console.log('Su Mo Tu We Th Fr Sa');

      let week = '';
      let dayCounter = 1;

      for (let i = 0; i < 6; i++) {
        for (let j = 0; j < 7; j++) {
          if (i === 0 && j < firstDay) {
            week += '   ';
          } else if (dayCounter <= daysInMonth) {
            week += `${dayCounter < 10 ? ' ' : ''}${dayCounter} `;
            dayCounter++;
          }
          if (dayCounter > daysInMonth) {
            break;
          }
        }
        if (dayCounter > daysInMonth) {
          break;
        }
        console.log(week);
        week = '';
      }
    }
    rl.close();
  }
});
