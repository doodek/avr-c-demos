// 
//  Font data for Minecraftia 6pt
// 
#include <avr/pgmspace.h>
#include "bajty_znaku.h"
// Character bitmaps for Minecraftia 6pt
const __flash char bajty_znaku[] = 
{
	// @0 '!' (1 pixels wide)
	0xBE, // # #####

	// @1 '"' (3 pixels wide)
	0xC0, // ##
	0x00, //   
	0xC0, // ##

	// @4 '#' (5 pixels wide)
	0x28, //   # #  
	0xFE, // #######
	0x28, //   # #  
	0xFE, // #######
	0x28, //   # #  

	// @9 '$' (5 pixels wide)
	0x48, //  #  #  
	0x54, //  # # # 
	0xD6, // ## # ##
	0x54, //  # # # 
	0x24, //   #  # 

	// @14 '%' (5 pixels wide)
	0x86, // #    ##
	0x60, //  ##    
	0x10, //    #   
	0x0C, //     ## 
	0xC2, // ##    #

	// @19 '&' (5 pixels wide)
	0x60, //  ##    
	0x94, // #  # # 
	0xBA, // # ### #
	0x64, //  ##  # 
	0x90, // #  #   

	// @24 ''' (1 pixels wide)
	0xC0, // ##

	// @25 '(' (4 pixels wide)
	0x38, //   ###  
	0x44, //  #   # 
	0x82, // #     #
	0x82, // #     #

	// @29 ')' (4 pixels wide)
	0x82, // #     #
	0x82, // #     #
	0x44, //  #   # 
	0x38, //   ###  

	// @33 '*' (4 pixels wide)
	0xA0, // # #
	0x40, //  # 
	0x40, //  # 
	0xA0, // # #

	// @37 '+' (5 pixels wide)
	0x20, //   #  
	0x20, //   #  
	0xF8, // #####
	0x20, //   #  
	0x20, //   #  

	// @42 ',' (1 pixels wide)
	0xE0, // ###

	// @43 '-' (5 pixels wide)
	0x10, // #
	0x10, // #
	0x10, // #
	0x10, // #
	0x10, // #

	// @48 '.' (1 pixels wide)
	0xC0, // ##

	// @49 '/' (5 pixels wide)
	0x80, // #      
	0x60, //  ##    
	0x10, //    #   
	0x0C, //     ## 
	0x02, //       #

	// @54 '0' (5 pixels wide)
	0x7C, //  ##### 
	0xA2, // # #   #
	0x92, // #  #  #
	0x8A, // #   # #
	0x7C, //  ##### 

	// @59 '1' (5 pixels wide)
	0x80, // #      
	0x84, // #    # 
	0xFE, // #######
	0x80, // #      
	0x80, // #      

	// @64 '2' (5 pixels wide)
	0xC4, // ##   # 
	0xA2, // # #   #
	0x92, // #  #  #
	0x92, // #  #  #
	0x8C, // #   ## 

	// @69 '3' (5 pixels wide)
	0x44, //  #   # 
	0x82, // #     #
	0x92, // #  #  #
	0x92, // #  #  #
	0x6C, //  ## ## 

	// @74 '4' (5 pixels wide)
	0x30, //   ##   
	0x28, //   # #  
	0x24, //   #  # 
	0x22, //   #   #
	0xFE, // #######

	// @79 '5' (5 pixels wide)
	0x4E, //  #  ###
	0x8A, // #   # #
	0x8A, // #   # #
	0x8A, // #   # #
	0x72, //  ###  #

	// @84 '6' (5 pixels wide)
	0x78, //  ####  
	0x94, // #  # # 
	0x92, // #  #  #
	0x92, // #  #  #
	0x60, //  ##    

	// @89 '7' (5 pixels wide)
	0x06, //      ##
	0x02, //       #
	0xE2, // ###   #
	0x12, //    #  #
	0x0E, //     ###

	// @94 '8' (5 pixels wide)
	0x6C, //  ## ## 
	0x92, // #  #  #
	0x92, // #  #  #
	0x92, // #  #  #
	0x6C, //  ## ## 

	// @99 '9' (5 pixels wide)
	0x0C, //     ## 
	0x92, // #  #  #
	0x92, // #  #  #
	0x52, //  # #  #
	0x3C, //   #### 

	// @104 ':' (1 pixels wide)
	0xCC, // ##  ##

	// @105 ';' (1 pixels wide)
	0xE6, // ###  ##

	// @106 '<' (4 pixels wide)
	0x10, //    #   
	0x28, //   # #  
	0x44, //  #   # 
	0x82, // #     #

	// @110 '=' (5 pixels wide)
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #

	// @115 '>' (4 pixels wide)
	0x82, // #     #
	0x44, //  #   # 
	0x28, //   # #  
	0x10, //    #   

	// @119 '?' (5 pixels wide)
	0x04, //      # 
	0x02, //       #
	0xA2, // # #   #
	0x12, //    #  #
	0x0C, //     ## 

	// @124 '@' (6 pixels wide)
	0x7C, //  ##### 
	0x82, // #     #
	0xBA, // # ### #
	0xBA, // # ### #
	0xA2, // # #   #
	0xBC, // # #### 

	// @130 'A' (5 pixels wide)
	0xFC, // ###### 
	0x0A, //     # #
	0x0A, //     # #
	0x0A, //     # #
	0xFC, // ###### 

	// @135 'B' (5 pixels wide)
	0xFE, // #######
	0x8A, // #   # #
	0x8A, // #   # #
	0x8A, // #   # #
	0x74, //  ### # 

	// @140 'C' (5 pixels wide)
	0x7C, //  ##### 
	0x82, // #     #
	0x82, // #     #
	0x82, // #     #
	0x44, //  #   # 

	// @145 'D' (5 pixels wide)
	0xFE, // #######
	0x82, // #     #
	0x82, // #     #
	0x82, // #     #
	0x7C, //  ##### 

	// @150 'E' (5 pixels wide)
	0xFE, // #######
	0x8A, // #   # #
	0x8A, // #   # #
	0x82, // #     #
	0x82, // #     #

	// @155 'F' (5 pixels wide)
	0xFE, // #######
	0x0A, //     # #
	0x0A, //     # #
	0x02, //       #
	0x02, //       #

	// @160 'G' (5 pixels wide)
	0x7C, //  ##### 
	0x82, // #     #
	0x8A, // #   # #
	0x8A, // #   # #
	0x7A, //  #### #

	// @165 'H' (5 pixels wide)
	0xFE, // #######
	0x08, //     #  
	0x08, //     #  
	0x08, //     #  
	0xFE, // #######

	// @170 'I' (3 pixels wide)
	0x82, // #     #
	0xFE, // #######
	0x82, // #     #

	// @173 'J' (5 pixels wide)
	0x40, //  #     
	0x80, // #      
	0x80, // #      
	0x80, // #      
	0x7E, //  ######

	// @178 'K' (5 pixels wide)
	0xFE, // #######
	0x08, //     #  
	0x08, //     #  
	0x14, //    # # 
	0xE2, // ###   #

	// @183 'L' (5 pixels wide)
	0xFE, // #######
	0x80, // #      
	0x80, // #      
	0x80, // #      
	0x80, // #      

	// @188 'M' (5 pixels wide)
	0xFE, // #######
	0x04, //      # 
	0x08, //     #  
	0x04, //      # 
	0xFE, // #######

	// @193 'N' (5 pixels wide)
	0xFE, // #######
	0x04, //      # 
	0x08, //     #  
	0x10, //    #   
	0xFE, // #######

	// @198 'O' (5 pixels wide)
	0x7C, //  ##### 
	0x82, // #     #
	0x82, // #     #
	0x82, // #     #
	0x7C, //  ##### 

	// @203 'P' (5 pixels wide)
	0xFE, // #######
	0x0A, //     # #
	0x0A, //     # #
	0x0A, //     # #
	0x04, //      # 

	// @208 'Q' (5 pixels wide)
	0x7C, //  ##### 
	0x82, // #     #
	0x82, // #     #
	0x42, //  #    #
	0xBC, // # #### 

	// @213 'R' (5 pixels wide)
	0xFE, // #######
	0x0A, //     # #
	0x0A, //     # #
	0x0A, //     # #
	0xF4, // #### # 

	// @218 'S' (5 pixels wide)
	0x44, //  #   # 
	0x8A, // #   # #
	0x8A, // #   # #
	0x8A, // #   # #
	0x72, //  ###  #

	// @223 'T' (5 pixels wide)
	0x02, //       #
	0x02, //       #
	0xFE, // #######
	0x02, //       #
	0x02, //       #

	// @228 'U' (5 pixels wide)
	0x7E, //  ######
	0x80, // #      
	0x80, // #      
	0x80, // #      
	0x7E, //  ######

	// @233 'V' (5 pixels wide)
	0x1E, //    ####
	0x60, //  ##    
	0x80, // #      
	0x60, //  ##    
	0x1E, //    ####

	// @238 'W' (5 pixels wide)
	0xFE, // #######
	0x40, //  #     
	0x20, //   #    
	0x40, //  #     
	0xFE, // #######

	// @243 'X' (5 pixels wide)
	0xE2, // ###   #
	0x14, //    # # 
	0x08, //     #  
	0x14, //    # # 
	0xE2, // ###   #

	// @248 'Y' (5 pixels wide)
	0x02, //       #
	0x04, //      # 
	0xF8, // #####  
	0x04, //      # 
	0x02, //       #

	// @253 'Z' (5 pixels wide)
	0xC2, // ##    #
	0xA2, // # #   #
	0x92, // #  #  #
	0x8A, // #   # #
	0x86, // #    ##

	// @258 '[' (3 pixels wide)
	0xFE, // #######
	0x82, // #     #
	0x82, // #     #

	// @261 '\' (5 pixels wide)
	0x02, //       #
	0x0C, //     ## 
	0x10, //    #   
	0x60, //  ##    
	0x80, // #      

	// @266 ']' (3 pixels wide)
	0x82, // #     #
	0x82, // #     #
	0xFE, // #######

	// @269 '^' (5 pixels wide)
	0x80, // #  
	0x40, //  # 
	0x20, //   #
	0x40, //  # 
	0x80, // #  

	// @274 '_' (5 pixels wide)
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #

	// @279 '`' (2 pixels wide)
	0x40, //  #
	0x80, // # 

	// @281 'a' (5 pixels wide)
	0x40, //  #   
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #
	0xF0, // #### 

	// @286 'b' (5 pixels wide)
	0xFE, // #######
	0x90, // #  #   
	0x88, // #   #  
	0x88, // #   #  
	0x70, //  ###   

	// @291 'c' (5 pixels wide)
	0x70, //  ### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x50, //  # # 

	// @296 'd' (5 pixels wide)
	0x70, //  ###   
	0x88, // #   #  
	0x88, // #   #  
	0x90, // #  #   
	0xFE, // #######

	// @301 'e' (5 pixels wide)
	0x70, //  ### 
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #
	0xB0, // # ## 

	// @306 'f' (4 pixels wide)
	0x08, //     #  
	0xFC, // ###### 
	0x0A, //     # #
	0x0A, //     # #

	// @310 'g' (5 pixels wide)
	0x98, // #  ## 
	0xA4, // # #  #
	0xA4, // # #  #
	0xA4, // # #  #
	0x7C, //  #####

	// @315 'h' (5 pixels wide)
	0xFE, // #######
	0x10, //    #   
	0x08, //     #  
	0x08, //     #  
	0xF0, // ####   

	// @320 'i' (1 pixels wide)
	0xFA, // ##### #

	// @321 'j' (5 pixels wide)
	0x60, //  ##     
	0x80, // #       
	0x80, // #       
	0x80, // #       
	0x7D, //  ##### #

	// @326 'k' (4 pixels wide)
	0xFE, // #######
	0x20, //   #    
	0x50, //  # #   
	0x88, // #   #  

	// @330 'l' (2 pixels wide)
	0x7E, //  ######
	0x80, // #      

	// @332 'm' (5 pixels wide)
	0xF8, // #####
	0x08, //     #
	0x30, //   ## 
	0x08, //     #
	0xF0, // #### 

	// @337 'n' (5 pixels wide)
	0xF8, // #####
	0x08, //     #
	0x08, //     #
	0x08, //     #
	0xF0, // #### 

	// @342 'o' (5 pixels wide)
	0x70, //  ### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x70, //  ### 

	// @347 'p' (5 pixels wide)
	0xFC, // ######
	0x28, //   # # 
	0x24, //   #  #
	0x24, //   #  #
	0x18, //    ## 

	// @352 'q' (5 pixels wide)
	0x18, //    ## 
	0x24, //   #  #
	0x24, //   #  #
	0x28, //   # # 
	0xFC, // ######

	// @357 'r' (5 pixels wide)
	0xF8, // #####
	0x10, //    # 
	0x08, //     #
	0x08, //     #
	0x10, //    # 

	// @362 's' (5 pixels wide)
	0x90, // #  # 
	0xA8, // # # #
	0xA8, // # # #
	0xA8, // # # #
	0x48, //  #  #

	// @367 't' (3 pixels wide)
	0x04, //      # 
	0x7E, //  ######
	0x84, // #    # 

	// @370 'u' (5 pixels wide)
	0x78, //  ####
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0xF8, // #####

	// @375 'v' (5 pixels wide)
	0x38, //   ###
	0x40, //  #   
	0x80, // #    
	0x40, //  #   
	0x38, //   ###

	// @380 'w' (5 pixels wide)
	0x78, //  ####
	0x80, // #    
	0xE0, // ###  
	0x80, // #    
	0xF8, // #####

	// @385 'x' (5 pixels wide)
	0x88, // #   #
	0x50, //  # # 
	0x20, //   #  
	0x50, //  # # 
	0x88, // #   #

	// @390 'y' (5 pixels wide)
	0x9C, // #  ###
	0xA0, // # #   
	0xA0, // # #   
	0xA0, // # #   
	0x7C, //  #####

	// @395 'z' (5 pixels wide)
	0x88, // #   #
	0xC8, // ##  #
	0xA8, // # # #
	0x98, // #  ##
	0x88, // #   #

	// @400 '{' (4 pixels wide)
	0x10, //    #   
	0x6C, //  ## ## 
	0x82, // #     #
	0x82, // #     #

	// @404 '|' (1 pixels wide)
	0xFF, // ########

	// @405 '}' (4 pixels wide)
	0x82, // #     #
	0x82, // #     #
	0x6C, //  ## ## 
	0x10, //    #   

	// @409 '~' (6 pixels wide)
	0x00, // # 
	0x00, //  #
	0x00, //  #
	0x00, // # 
	0x00, // # 
	0x00 //  #
};

// Character descriptors for Minecraftia 6pt
// { [Char width in bits], [Offset into minecraftia_6ptCharBitmaps in bytes] }
const __flash int dlugosc_indeks_znaku[][2] = 
{
	{1, 0}, 		// ! 
	{3, 1}, 		// " 
	{5, 4}, 		// # 
	{5, 9}, 		// $ 
	{5, 14}, 		// % 
	{5, 19}, 		// & 
	{1, 24}, 		// ' 
	{4, 25}, 		// ( 
	{4, 29}, 		// ) 
	{4, 33}, 		// * 
	{5, 37}, 		// + 
	{1, 42}, 		// , 
	{5, 43}, 		// - 
	{1, 48}, 		// . 
	{5, 49}, 		// / 
	{5, 54}, 		// 0 
	{5, 59}, 		// 1 
	{5, 64}, 		// 2 
	{5, 69}, 		// 3 
	{5, 74}, 		// 4 
	{5, 79}, 		// 5 
	{5, 84}, 		// 6 
	{5, 89}, 		// 7 
	{5, 94}, 		// 8 
	{5, 99}, 		// 9 
	{1, 104}, 		// : 
	{1, 105}, 		// ; 
	{4, 106}, 		// < 
	{5, 110}, 		// = 
	{4, 115}, 		// > 
	{5, 119}, 		// ? 
	{6, 124}, 		// @ 
	{5, 130}, 		// A 
	{5, 135}, 		// B 
	{5, 140}, 		// C 
	{5, 145}, 		// D 
	{5, 150}, 		// E 
	{5, 155}, 		// F 
	{5, 160}, 		// G 
	{5, 165}, 		// H 
	{3, 170}, 		// I 
	{5, 173}, 		// J 
	{5, 178}, 		// K 
	{5, 183}, 		// L 
	{5, 188}, 		// M 
	{5, 193}, 		// N 
	{5, 198}, 		// O 
	{5, 203}, 		// P 
	{5, 208}, 		// Q 
	{5, 213}, 		// R 
	{5, 218}, 		// S 
	{5, 223}, 		// T 
	{5, 228}, 		// U 
	{5, 233}, 		// V 
	{5, 238}, 		// W 
	{5, 243}, 		// X 
	{5, 248}, 		// Y 
	{5, 253}, 		// Z 
	{3, 258}, 		// [ 
	{5, 261}, 		
	{3, 266}, 		// ] 
	{5, 269}, 		// ^ 
	{5, 274}, 		// _ 
	{2, 279}, 		// ` 
	{5, 281}, 		// a 
	{5, 286}, 		// b 
	{5, 291}, 		// c 
	{5, 296}, 		// d 
	{5, 301}, 		// e 
	{4, 306}, 		// f 
	{5, 310}, 		// g 
	{5, 315}, 		// h 
	{1, 320}, 		// i 
	{5, 321}, 		// j 
	{4, 326}, 		// k 
	{2, 330}, 		// l 
	{5, 332}, 		// m 
	{5, 337}, 		// n 
	{5, 342}, 		// o 
	{5, 347}, 		// p 
	{5, 352}, 		// q 
	{5, 357}, 		// r 
	{5, 362}, 		// s 
	{3, 367}, 		// t 
	{5, 370}, 		// u 
	{5, 375}, 		// v 
	{5, 380}, 		// w 
	{5, 385}, 		// x 
	{5, 390}, 		// y 
	{5, 395}, 		// z 
	{4, 400}, 		// { 
	{1, 404}, 		// | 
	{4, 405}, 		// } 
	{6, 409} 		// ~ 
};


