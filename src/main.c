#include "main.h"

#define WORKSPACE_PATH Str8("D:\\work\\project_checker\\dummy")

void entry_point() {
  Arena_Temp scratch = scratch_begin(0, 0);
  win32_enable_console();
  
  File_List files = file_get_all_files_in_path_recursively(scratch.arena, WORKSPACE_PATH, (FileFlag_WhiteList | FileFlag_CFiles | FileFlag_HFiles | FileFlag_Dirs));
  File_Node* current_file = files.first;

  while (current_file != NULL) {
    printf("\n\n"); string8_printf(current_file->value.path); printf("\n\n");

    Lexer lexer;
    lexer_init(&lexer, current_file->value.path);

    Parser parser;
    parser_init(&parser, &lexer);

    AST_Node* ast = parser_parse_file(&parser);
    ast_print(ast);

    current_file = current_file->next;
    break;
  }

  system("pause");
}