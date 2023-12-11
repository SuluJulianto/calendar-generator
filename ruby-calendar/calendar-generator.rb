require 'date'

print 'Enter a year (1-9999): '
year = gets.chomp.to_i

if year < 1 || year > 9999
  puts 'Please choose another year within the range.'
else
  (1..12).each do |month|
    month_name = Date.new(year, month, 1).strftime('%B')
    puts "\n#{month_name} #{year}"
    puts 'Su Mo Tu We Th Fr Sa'

    first_day = Date.new(year, month, 1).cwday
    days_in_month = Date.new(year, month, -1).day

    week = ' ' * (first_day % 7) * 4
    
    (1..days_in_month).each do |day|
      week += "#{' ' if day < 10}#{day} "
      week += "\n" if (first_day + day) % 7 == 0 || day == days_in_month
    end

    puts week
  end
end
