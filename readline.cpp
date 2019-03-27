// Gnu Readline Sample
//
// * [Run]
//    > g++ readline.cpp -lreadline
//    or
//    > make SRC=readline.cpp LINKOPT=-lreadline
//

// 下記を include する
#include <cstdio>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
	char *command;
	
	using_history();
	read_history(".my_history"); // [ToDo]historyファイルが無いときの動作の検証
	while(1) {
		 command = readline(">> ");
		 add_history(command);
		 
		 /* コマンドの処理 */
		 
		 //free(command);
                 printf("%s", command);
	}
	write_history(".my_history");

	return 0;
}
