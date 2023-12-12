package main

import (
	"fmt"
	"time"
)

func main() {
	var year int
	fmt.Print("Enter a year (1-9999): ")
	fmt.Scanln(&year)

	if year < 1 || year > 9999 {
		fmt.Println("Please choose another year within the range.")
	} else {
		for month := 1; month <= 12; month++ {
			currentDate := time.Date(year, time.Month(month), 1, 0, 0, 0, 0, time.UTC)
			monthName := currentDate.Month().String()

			fmt.Printf("\n%s %d\n", monthName, year)
			fmt.Println("Su Mo Tu We Th Fr Sa")

			daysInMonth := daysInMonth(year, month)
			firstDay := time.Date(year, time.Month(month), 1, 0, 0, 0, 0, time.UTC).Weekday()

			week := ""
			for i := 0; i < int(firstDay); i++ {
				week += "   "
			}

			for day := 1; day <= daysInMonth; day++ {
				week += fmt.Sprintf("%2d ", day)
				if (int(firstDay)+day)%7 == 0 || day == daysInMonth {
					fmt.Println(week)
					week = ""
				}
			}
		}
	}
}

func daysInMonth(year, month int) int {
	switch month {
	case 2:
		if year%4 == 0 && (year%100 != 0 || year%400 == 0) {
			return 29
		}
		return 28
	case 4, 6, 9, 11:
		return 30
	default:
		return 31
	}
}
