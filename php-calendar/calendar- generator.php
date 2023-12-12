<?php
echo "Enter a year (1-9999): ";
$year = readline();

if ($year < 1 || $year > 9999 || !is_numeric($year)) {
    echo "Please choose another year within the range.";
    exit();
}

for ($month = 1; $month <= 12; $month++) {
    $monthName = date('F', mktime(0, 0, 0, $month, 1, $year));
    $daysInMonth = date('t', mktime(0, 0, 0, $month, 1, $year));
    $firstDay = date('w', mktime(0, 0, 0, $month, 1, $year));

    echo "\n" . $monthName . ' ' . $year . "\n";
    echo "Su Mo Tu We Th Fr Sa\n";

    $dayCounter = 1;

    for ($i = 0; $i < 6; $i++) {
        $week = '';
        for ($j = 0; $j < 7; $j++) {
            if (($i === 0 && $j < $firstDay) || $dayCounter > $daysInMonth) {
                $week .= '   ';
            } else {
                $week .= ($dayCounter < 10 ? ' ' : '') . $dayCounter . ' ';
                $dayCounter++;
            }
        }
        echo $week . "\n";

        if ($dayCounter > $daysInMonth) {
            break;
        }
    }
}
?>
