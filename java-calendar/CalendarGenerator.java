import java.util.Scanner;
import java.time.LocalDate;
import java.time.ZoneId;
import java.time.format.TextStyle;
import java.util.Locale;

public class CalendarPrinter {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a year (1-9999): ");
        int year = scanner.nextInt();

        if (year < 1 || year > 9999) {
            System.out.println("Please choose another year within the range.");
        } else {
            for (int month = 1; month <= 12; month++) {
                System.out.println("\n" + monthToString(month) + " " + year);
                System.out.println("Su Mo Tu We Th Fr Sa");

                int daysInMonth = daysInMonth(year, month);
                int firstDay = firstDayOfWeek(year, month);

                StringBuilder week = new StringBuilder();
                for (int i = 1; i < firstDay; i++) {
                    week.append("   ");
                }
                for (int day = 1; day <= daysInMonth; day++) {
                    week.append(String.format("%2d ", day));
                    if ((firstDay + day - 1) % 7 == 0 || day == daysInMonth) {
                        System.out.println(week);
                        week = new StringBuilder();
                    }
                }
            }
        }
        scanner.close();
    }

    private static int daysInMonth(int year, int month) {
        return switch (month) {
            case 2 -> (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
            case 4, 6, 9, 11 -> 30;
            default -> 31;
        };
    }

    private static int firstDayOfWeek(int year, int month) {
        return LocalDate.of(year, month, 1).atStartOfDay(ZoneId.of("Asia/Jakarta")).getDayOfWeek().getValue();
    }

    private static String monthToString(int month) {
        return LocalDate.of(2000, month, 1).getMonth().getDisplayName(TextStyle.FULL, Locale.ENGLISH);
    }
}
