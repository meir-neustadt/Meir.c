#include "Board.h"

void clean_board(CELL board[3][3])
{
	CELL A = EMPTY_CELL;
        board[0][0] = board[0][1] = board[0][2] = board[1][0] = board[1][1] = board[1][2] =
		board[2][0] = board[2][1] = board[2][2] = A;
}

void set_cell(CELL board[3][3], uint8_t row_index, uint8_t column_index, CELL value)
{
	board[row_index][column_index] = value;
}

CELL get_cell(CELL board[3][3], uint8_t row_index, uint8_t column_index)
{
	return board[row_index][column_index];
}

CELL who_wins_at_row(CELL board[3][3], uint8_t row_index)
{
	CELL A = EMPTY_CELL;
	if(board[row_index][0]==board[row_index][1] && board[row_index][0] == board[row_index][2]) return board[row_index][2];
	return A;
}

CELL who_wins_at_column(CELL board[3][3], uint8_t col_index)
{
	CELL A = EMPTY_CELL;
	if (board[0][col_index] == board[1][col_index] && board[0][col_index] == board[2][col_index]) return board[0][col_index];
	return A;
}

CELL who_wins_at_diagonal(CELL board[3][3], bool is_top_left_to_bottom_right)
{
	CELL A = EMPTY_CELL;
	if (is_top_left_to_bottom_right)
	{
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return board[2][2];
	}
	else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) return board[2][0];
	return A;
}

CELL who_won(CELL board[3][3])
{
	CELL A = EMPTY_CELL;
	for (uint8_t i = 0; i < 3; i++) {
		if (who_wins_at_row(board,i) != EMPTY_CELL)return(who_wins_at_row(board,i));
	}
	for (uint8_t i = 0; i < 3; i++) {
		if (who_wins_at_column(board, i) != EMPTY_CELL)return(who_wins_at_column(board, i));
	}
	bool is_top_left_to_bottom_right = true;
	if (who_wins_at_diagonal(board, is_top_left_to_bottom_right) != EMPTY_CELL)return(who_wins_at_diagonal(board, is_top_left_to_bottom_right));
	is_top_left_to_bottom_right = false;
	if (who_wins_at_diagonal(board, is_top_left_to_bottom_right) != EMPTY_CELL)return(who_wins_at_diagonal(board, is_top_left_to_bottom_right));
	return A;
}

bool is_board_full(CELL board[3][3])
{
	CELL A = EMPTY_CELL;
	for (uint8_t i = 0; i < 3; ++i) { for (uint8_t j = 0; j < 3; ++j) { if (board[i][j] == A)return false; } }
	return true;
}
