#include <iostream>
#include <iomanip>

const int TOTAL_ROWS = 10;
const int SEATS_PER_ROW = 4;

struct Row
{
  char seats[SEATS_PER_ROW];
};

void create_seats(Row seatingChart[])
{
  for (int i = 0; i < TOTAL_ROWS; ++i)
  {
    char seatLetter = 'A'; 
    for(int j = 0; j < SEATS_PER_ROW; ++j)
    {
      seatingChart[i].seats[j] = seatLetter++;
}}}

void show_seats(const Row seatingChart[])
{
  std::cout << "Current Seating Chart:" << std::endl;

  for (int rowNumber = 0; rowNumber < TOTAL_ROWS; ++rowNumber)
  {
    std::cout << std::setw(2) << rowNumber + 1 << " ";

    for (int seatNumber = 0; seatNumber < SEATS_PER_ROW; ++seatNumber)
    {
      std::cout << seatingChart[rowNumber].seats[seatNumber] << " ";
    }
    std::cout << std::endl;
}}

bool seat_availability(const Row seatingChart[], int row, char seat)
{
  for (int i = 0; i < SEATS_PER_ROW; i++)
  {
    if (seatingChart[row - 1].seats[i] == seat)
    {
      return true;
    }
    return false;
}}

void book_seats(Row seatingChart[], int row, char seat)
{
  for (int i = 0; i < SEATS_PER_ROW; ++i)
  {
    if (seatingChart[row - 1].seats[i] == seat)
    {
      seatingChart[row - 1].seats[i] = 'X';
      break;
}}}

int main()
{
  Row seatingChart[TOTAL_ROWS];
  create_seats(seatingChart);

  char cont;
  
  do
  {
    int row;
    char seat;
    bool occupied = false;

    while(!occupied)
    {
      show_seats(seatingChart);
      
      std::cout << "Enter row number and seat letter (e.g. 2A): ";
      std::cin >> row >> seat;

      if (row < 1 || row > TOTAL_ROWS || seat < 'A' || seat > 'A' + SEATS_PER_ROW - 1)
      {
        std::cout << "Invalid input. Please try again." << std::endl;
      }
      else if (!seat_availability(seatingChart, row, seat))
      {
        std::cout << "Seat " << row << seat << " is already taken. Please try again." << std::endl;
      }
      else 
      {
        occupied = true;
      }
    }
    
    book_seats(seatingChart, row, seat);

    std::cout << "Would you like to book another seat? [Y/n]: ";
    std::cin >> cont;

  } while (cont != 'n' && cont != 'N');

  return 0;

}