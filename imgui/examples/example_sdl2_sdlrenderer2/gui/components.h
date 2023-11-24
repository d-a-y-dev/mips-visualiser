#include "SDL2/SDL.h"

void draw_fetch_mux(SDL_Renderer* renderer, SDL_Color color);

void draw_fetch_pc(SDL_Renderer* renderer, SDL_Color color);

void draw_decode_decoder(SDL_Renderer* renderer, SDL_Color color);

void draw_decode_register_files(SDL_renderer* renderer, SDL_Color color);

void draw_decode_mux_to_alu(SDL_renderer* renderer, SDL_Color color);

void draw_decode_mux_to_fetch(SDL_renderer* renderer, SDL_Color color);

void draw_execute_alu(SDL_Renderer* renderer, SDL_Color color);

void draw_memory_main_memory(SDL_Renderer* renderer, SDL_Color color);

void draw_line_pc_to_main_memory(SDL_Renderer* renderer, SDL_Color color);

void draw_line_mux_to_pc(SDL_Renderer* renderer, SDL_Color color);

void draw_line_main_memory_to_decoder(SDL_Renderer* renderer, SDL_Color color);

void draw_line_decoder_to_mux_sel(SDL_Renderer* renderer, SDL_Color color);

void draw_line_decoder_to_mux_imm(SDL_Renderer* renderer, SDL_Color color);

void draw_line_decoder_to_mux_to_fetch(SDL_Renderer* renderer, SDL_Color color);

void draw_line_decoder_to_mux_to_alu_imm(SDL_Renderer* renderer, SDL_Color color);

void draw_line_decoder_to_mux_to_alu_sel(SDL_Renderer* renderer, SDL_Color color);

void draw_line_register_files_to_fetch_mux(SDL_Renderer* renderer, SDL_Color color);

void draw_line_register_files_to_mux_to_alu(SDL_Renderer* renderer, SDL_Color color);

void draw_line_decode_mux_to_alu(SDL_Renderer* renderer, SDL_Color color);

void draw_line_alu_to_main_memory_data(SDL_Renderer* renderer, SDL_Color color);

void draw_line_alu_to_main_memory_address(SDL_Renderer* renderer, SDL_Color color);

void draw_line_alu_to_mux_to_pc(SDL_Renderer* renderer, SDL_Color color);

void draw_line_main_memory_to_mux_to_pc(SDL_Renderer* renderer, SDL_Color color);

void draw_line_mux_to_mux(SDL_Renderer* renderer, SDL_Color color);