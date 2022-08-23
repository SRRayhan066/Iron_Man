#include<iostream>
#include<sstream>
using namespace std;
# include "iGraphics.h"
int mposx,  mposy;

# define width 1500
# define height 750

int game_state = -1;

char menu_button[30][30] = { "iron_pic\\play.bmp", "iron_pic\\instructions.bmp", "iron_pic\\settings.bmp", "iron_pic\\about.bmp" };
int menu_buttonx[4] = { 200, 373, 280, 236 };
int menu_indx = 0;
bool start = true;
int start_counter = 0;
char start_pic[6][30] = { "iron_pic\\MAIN_STORY_1.bmp", "iron_pic\\MAIN_STORY_2.bmp", "iron_pic\\MAIN_STORY_3.bmp","iron_pic\\MAIN_STORY_4.bmp","iron_pic\\Round1_big.bmp" };
int start_indx = 0;
bool music = true;

char shoot_5[30][30] = {"iron_pic\\shoot5.bmp"};
bool iron_shoot = false;
bool iron_shoot_ind = false;
int iron_shoot_counter = 0;
int shootx = 0;
int iron_health = 3000;
int iron_gain = 0;
char iron_kill[30][30] = { "iron_pic\\iron_kill_1.bmp", "iron_pic\\iron_kill_2.bmp", "iron_pic\\iron_kill_3.bmp", "iron_pic\\iron_kill_4.bmp", "iron_pic\\iron_kill_5.bmp" };
int iron_kill_indx = 0;
int iron_kill_counter = 0;
int key_5_counter = 2;
char iron_health_bar[30][30] = {"iron_pic\\Iron_Man_0.bmp", "iron_pic\\Iron_Man_25.bmp", "iron_pic\\Iron_Man_50.bmp" , "iron_pic\\Iron_Man_75.bmp" , "iron_pic\\Iron_Man_100.bmp" };
int iron_health_index = 4;
int iron_wins_rate = 0;
int iron_win = 0;
int win_counter = 0;


char max_shot[30][30] = { "iron_pic\\max_shoot1.bmp","iron_pic\\max_shoot1.bmp","iron_pic\\max_shoot1.bmp", "iron_pic\\max_shoot2.bmp", "iron_pic\\max_shoot3.bmp", "iron_pic\\max_shoot4.bmp" };
int max_shoot_indx = 0;
int max_power_counter = 0;
bool max_power = false;
bool lighting_blust = false;
int mx_shootx = 0;
int mx_shoot_counter = 0;

int flying_counter = 0;
bool right_flying = false;
bool left_flying = false;
bool up_flying = false;
bool up = true;

char ultron_ground_shoot[60][60] = {"iron_pic\\ultron_ground_shoot1.bmp","iron_pic\\ultron_ground_shoot2.bmp"};
int ultrons_shoot_point[15] = {48,67,72,170,67,156,66,79,83,145};
int ultrons_shooot_indx = 0;
int ultron_counter = 0;
int ultron_lim = 350;
int ultron_shoot = 0; // the lighting position of ultron's shoot
int ultron_health = 3000;
char ultron_kill[35][35] = { "iron_pic\\ultron_kill_1.bmp", "iron_pic\\ultron_kill_2.bmp", "iron_pic\\ultron_kill_3.bmp", "iron_pic\\ultron_kill_4.bmp", "iron_pic\\ultron_kill_5.bmp", "iron_pic\\ultron_kill_6.bmp" };
int ultron_kill_indx = 0;
int ultron_kill_counter = 0;
char ultron_health_bar[30][30] = {"iron_pic\\Ultron_0.bmp", "iron_pic\\Ultron_25.bmp", "iron_pic\\Ultron_50.bmp", "iron_pic\\Ultron_75.bmp", "iron_pic\\Ultron_100.bmp"};
int ultron_health_index = 4;
int ultrons_win_rate = 0;
int ultron_win = 0;
bool ultron_dialougue = true;
char ultron_dialougue_pic[30][30] = { "iron_pic\\ULTRON_1.bmp", "iron_pic\\ULTRON_2.bmp", "iron_pic\\ULTRON_3.bmp", "iron_pic\\ULTRON_4.bmp", "iron_pic\\ULTRON_5.bmp", "iron_pic\\ULTRON_6.bmp" };
int ultron_dialougue_indx = 0;
int ultron_dialougue_counter = 0;

bool level1 = true;
bool level2 = false;
bool level3 = false;

bool round1 = true;
bool round2 = false;
bool round3 = false;
int round_counter = 0;
int round1_counter = 0;
bool round1_big = true;

bool Doom_dialouge = false;
char Doom_dialouge_pic[30][30] = { "iron_pic\\DR.DOOM_1.bmp", "iron_pic\\DR.DOOM_2.bmp", "iron_pic\\DR.DOOM_3.bmp", "iron_pic\\DR.DOOM_4.bmp", "iron_pic\\DR.DOOM_5.bmp", "iron_pic\\DR.DOOM_6.bmp" };
int Doom_dialougue_indx = 0;
int Doom_dialougue_counter = 0;
int Doom_counter = 0;
int Doom_health = 3500;
char Doom_ground_shoot[30][30] = { "iron_pic\\Dfire_1.bmp", "iron_pic\\Dfire_2.bmp", "iron_pic\\Dfire_3.bmp", "iron_pic\\Dfire_4.bmp" };
int Doom_ground_shoot_indx = 0;
int Doom_shoot_indx_counter = 0;
char Doom_flying_up[10][30] = {"iron_pic\\Doom_fly_2.bmp","iron_pic\\Doom_fly_3.bmp","iron_pic\\Doom_fly_4.bmp"};
int Doom_flying_indx = 0;
int Doom_flying_indx_counter = 0;
int Doom_shoot_point[15] = { 38, 67, 72, 170, 67, 156, 66, 79, 83, 145 };
int Doom_shoot_indx = 0;
char Doom_float[5][40] = { "iron_pic\\Doom_float_1.bmp","iron_pic\\Doom_float_2.bmp","iron_pic\\Doom_float_3.bmp"};
int Doom_float_indx = 0;
int Doom_float_indx_counter = 0;
char Doom_flying_left[5][40] = { "iron_pic\\Doom_left_fly_1.bmp", "iron_pic\\Doom_left_fly_2.bmp", "iron_pic\\Doom_left_fly_3.bmp" };
int Doom_left_fly_indx = 0;
int Doom_left_fly_counter = 0;
char Doom_flying_right[5][40] = { "iron_pic\\Doom_right_fly_1.bmp", "iron_pic\\Doom_right_fly_2.bmp", "iron_pic\\Doom_right_fly_3.bmp" };
int Doom_right_fly_indx = 0;
int Doom_right_fly_counter = 0;
int Dooms_win_rate = 0;
char Doom_health_bar[30][30] = { "iron_pic\\Dr.Doom_0.bmp", "iron_pic\\Dr.Doom_25.bmp", "iron_pic\\Dr.Doom_50.bmp", "iron_pic\\Dr.Doom_75.bmp", "iron_pic\\Dr.Doom_100.bmp" };
int Doom_health_index = 4;
char Doom_falling_down[6][40] = { "iron_pic\\Doom_falling_down_1.bmp", "iron_pic\\Doom_falling_down_2.bmp", "iron_pic\\Doom_falling_down_3.bmp", "iron_pic\\Doom_falling_down_4.bmp", "iron_pic\\Doom_falling_down_5.bmp" };
int Doom_falling_indx = 0;
int Doom_falling_counter = 0;
int Doom_kill_counter = 0;
int Doom_kill_indx = 0;
char Doom_kill[5][30] = { "iron_pic\\Doom_break_1.bmp", "iron_pic\\Doom_break_2.bmp", "iron_pic\\Doom_break_3.bmp", "iron_pic\\Doom_break_4.bmp" };

struct menu_cordinate{
	int x;
	int y;
}mn_button_pos[4];

struct running{
	int x;
	int y;
}run;

struct ultron_run{
	int x;
	int y;
}ultron;

struct doom_run{
	int x;
	int y;
}Doom;

void Ultron_shoot_func(){

	iShowBMP2(ultron.x, ultron.y, ultron_ground_shoot[1], 0);
	if (ultron_health > 0 && ultron.x - ultron_shoot - 50 <= run.x + ultrons_shoot_point[ultrons_shooot_indx]){
		ultron_shoot = 0;
	}
	ultron_counter++;
	while (ultron_health > 0 && ultron.x - ultron_shoot - 50 >= run.x + ultrons_shoot_point[ultrons_shooot_indx]){
		iShowBMP2(ultron.x - ultron_shoot - 50, ultron.y + 130, "iron_pic\\ultron_shoot.bmp", 0);
		ultron_shoot += 10;
	}

	iron_health -= 25;
	if (iron_health <= 0) iron_health = 0;

}


void Doom_shoot_func(){
	
		iShowBMP2(Doom.x, Doom.y, Doom_ground_shoot[Doom_ground_shoot_indx], 0);

		Doom_shoot_indx_counter++;
		if (Doom_shoot_indx_counter > 1){
			Doom_shoot_indx_counter = 0;
			Doom_ground_shoot_indx++;
			if (Doom_ground_shoot_indx >= 4) Doom_ground_shoot_indx = 0;
		}


		if (Doom_health > 0 && Doom.x - ultron_shoot - 50 <= run.x + ultrons_shoot_point[ultrons_shooot_indx]){
			ultron_shoot = 0;
		}
		Doom_counter++;
		while (Doom_health > 0 && Doom.x - ultron_shoot >= run.x + ultrons_shoot_point[ultrons_shooot_indx]){//notice
			iShowBMP2(Doom.x - ultron_shoot - 5, Doom.y + 195, "iron_pic\\Doom_blust_2.bmp", 0);  //changeable
			ultron_shoot += 30;
		}

		iron_health -= 25;
		if (iron_health <= 0) iron_health = 0;
	
}

void Doom_float_func(){

	iShowBMP2(Doom.x, Doom.y, Doom_float[Doom_float_indx], 0);

	Doom_float_indx_counter++;
	if (Doom_float_indx_counter > 5){
		Doom_float_indx_counter = 0;
		Doom_float_indx++;
		if (Doom_float_indx > 2) Doom_float_indx = 1;
	}

}

void iDraw()
{
	iClear();

	/*
	   Game state is declared for the different page
	   game state = -1 indicates the home/menu
	   game state = 0 for the main page where the game will be played
	   game state = 1 for instructions
	   game state = 2 for setting
	   game state = 3 for about
	   */

	if (game_state == -1){
		iShowBMP(0, 0, "iron_pic\\MainMenu.bmp");
		
		
		run.x = 50;
		run.y = 10;
		ultron.x = 1250;
		ultron.y = 5;
		Doom.x = 1100;
		Doom.y = 5;
		ultrons_shooot_indx = 0;
		Doom_shoot_indx = 0;
		ultron_health = 3000;
		iron_health = 3000;
		iron_kill_indx = 0;
		ultron_counter = 0;
		for (int i = 0; i < 4; i++)
			iShowBMP2(mn_button_pos[i].x, mn_button_pos[i].y, menu_button[i], 0);
	}

	else if (game_state == 10){
		//iShowBMP(0, 0, "iron_pic\\game_over.bmp");
		round_counter++;
		if (round_counter > 0 && round_counter <= 80){
			if (round2) iShowBMP(0, 0, "iron_pic\\Round2_big.bmp");
			else if (round3) iShowBMP(0, 0, "iron_pic\\Round3_big.bmp");
		}
		else if (round_counter > 80){
			ultron_health = 3000;
			iron_health = 3000;
			Doom_health = 3500;
			run.x = 50;
			run.y = 10;
			ultron.x = 1250;
			ultron.y = 5;
			Doom.x = 1100;
			Doom.y = 5;
			ultrons_shooot_indx = 0;
			Doom_shoot_indx = 0;
			ultron_kill_indx = 0;
			Doom_health_index = 4;
			iron_kill_indx = 0;
			ultron_counter = 0;
			Doom_counter = 0;		
			mx_shoot_counter = 0;
			max_power = false;
			iron_shoot = false;
			Doom_falling_indx = 0;
			Doom_kill_indx = 0;
			game_state = 0;
			round_counter = 0;
		}
	}

	else if (game_state == 11){
		iShowBMP(0, 0, "iron_pic\\You_lose.bmp");
	}


	else if (game_state == 0){


		if (start){
			iShowBMP(0, 0, start_pic[start_indx]); //round 1 pic
			start_counter++;
			if (start_counter >= 10){
				start_indx++;
				if (start_indx >= 4){
					start = false;
				}
				start_counter = 0;
			}
		}

		else if (!start && ultron_dialougue){
			iShowBMP(0, 0, ultron_dialougue_pic[ultron_dialougue_indx]);
			ultron_dialougue_counter++;
			if (ultron_dialougue_counter >= 10){  //changable
				ultron_dialougue_indx++;
				if (ultron_dialougue_indx >= 5){
					ultron_dialougue_indx = 5;
					ultron_dialougue = false;
				}
				ultron_dialougue_counter = 0;
			}
		}

		else if (!start && !ultron_dialougue &&round1_big){
			round1_counter++;
			if (round1_counter > 0 && round1_counter <= 80)
				iShowBMP(0, 0, "iron_pic\\Round1_big.bmp");
			else if (round1_counter > 80)                       //round1 pic set
			{
				round1_counter = 0;
				round1_big = false;
			}
		}

		else if (!start && level1){
			iShowBMP(0, 0, "iron_pic\\new_bc.bmp"); //background pic


			if (iron_health == 0) iron_health_index = 0;
			else if (iron_health > 0 && iron_health <= 750) iron_health_index = 1;
			else if (iron_health > 750 && iron_health <= 1500) iron_health_index = 2;   //Health bar for iron man
			else if (iron_health > 1500 && iron_health <= 2250) iron_health_index = 3;
			else if (iron_health > 2250 && iron_health <= 3000) iron_health_index = 4;

			iShowBMP2(50, 550, iron_health_bar[iron_health_index], 0);


			if (ultron_health == 0) ultron_health_index = 0;
			else if (ultron_health > 0 && ultron_health <= 750) ultron_health_index = 1;
			else if (ultron_health > 750 && ultron_health <= 1500) ultron_health_index = 2;  //Health bar for ultron
			else if (ultron_health > 1500 && ultron_health <= 2250) ultron_health_index = 3;
			else if (ultron_health > 2250 && ultron_health <= 3000) ultron_health_index = 4;

			iShowBMP2(1000, 550, ultron_health_bar[ultron_health_index], 0);


			//ultron start
			ultron_counter++;
			if (ultron_health > 0 && ultron_counter <= 100)
			{
				if (ultron_health > 0 && ultron_counter <= 30)  iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_standing.bmp", 0); //ultron stand on ground 

				else if (ultron_health > 0 && run.y <= 218 && ultron_counter > 30 && ultron_counter <= 65) iShowBMP2(ultron.x, ultron.y, ultron_ground_shoot[0], 0); //run.y indicates the vertical position of iron man 

				else if (ultron_health > 0 && run.y <= 218 && ultron_counter > 65 && ultron_counter <= 80){
					// Under the ultron shoot function
					
					Ultron_shoot_func();

					// Under the ultron shoot function
				}
				else if (ultron_health > 0 && ultron_counter > 80) iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_standing.bmp", 0);

				else  iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_standing.bmp", 0);
			} // Ultrn is standing and fighting on ground 

			else if (ultron_health > 0 && ultron_counter > 100 && ultron_counter <= 190)
			{
				ultron.y += 5;
				if (ultron.y >= ultron_lim) ultron.y = ultron_lim;
				iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_flying_up.bmp", 0);
			} // Ultron is flying up

			else if (ultron_health > 0 && ultron_counter > 190 && ultron_counter <= 450){

				if (ultron_health > 0 && ultron.y + 130 <= run.y + 150 && ultron.y + 130 >= run.y + 100){
					Ultron_shoot_func();
				}

				else iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_air_stand.bmp", 0);
			} // Ultron is standing and fighting on air

			else if (ultron_health > 0 && ultron_counter > 450 && ultron_counter <= 550){
				ultron.x -= 5;
				iShowBMP2(ultron.x, ultron.y + 75, "iron_pic\\ultron_flying_left.bmp", 0);
			} // Ultron is coming toward Iron man

			else if (ultron_health > 0 && ultron_counter > 550 && ultron_counter <= 700)
			{
				if (ultron_health > 0 && ultron.y + 130 <= run.y + 150 && ultron.y + 130 >= run.y + 100){
					Ultron_shoot_func();
				}

				else iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_air_stand.bmp", 0);
			} // Ultron is standing and fighting on air

			else if (ultron_health > 0 && ultron_counter > 700 && ultron_counter <= 750){
				ultron.y -= 5;
				iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_flying_down.bmp", 0);
			} //Ultron is flying down

			else if (ultron_health > 0 && ultron_counter > 750 && ultron_counter <= 1000){
				if (ultron.y + 130 <= run.y + 150 && ultron.y + 130 >= run.y + 100){
					Ultron_shoot_func();
				}
				else
					iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_air_stand.bmp", 0);
			} // Ultron is standing and fighting on air

			else if (ultron_health > 0 && ultron_counter > 1000 && ultron_counter <= 1050){
				ultron.y += 5;
				if (ultron.y >= ultron_lim) ultron.y = ultron_lim;
				iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_flying_up.bmp", 0);
			}  //Ultron is flying up

			else if (ultron_health > 0 && ultron_counter > 1050 && ultron_counter <= 1300){
				if (ultron_health > 0 && ultron.y + 130 <= run.y + 150 && ultron.y + 130 >= run.y + 100){
					Ultron_shoot_func();
				}
				else iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_air_stand.bmp", 0);
			}// Ultron is standing and fighting on air

			else if (ultron_health > 0 && ultron_counter > 1300 && ultron_counter <= 1400)
			{
				ultron.x += 5;
				iShowBMP2(ultron.x, ultron.y + 75, "iron_pic\\ultron_flying_right.bmp", 0);
			} //Ultron is flying right

			else if (ultron_health > 0 && ultron_counter > 1400 && ultron_counter < 1650){
				if (ultron_health > 0 && ultron.y + 130 <= run.y + 150 && ultron.y + 130 >= run.y + 100){
					Ultron_shoot_func();
				}
				else iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_air_stand.bmp", 0);
			} // Ultron is standing and fighting on air

			else if (ultron_health > 0 && ultron_counter > 1650){
				if (ultron.y <= 10) ultron_counter = 0;
				ultron.y -= 5;
				iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_flying_down.bmp", 0);
			} //Ultron is flying down

			else if (ultron_health > 0 && ultron.y > 5)   iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_air_stand.bmp", 0);

			else if (ultron_health == 0){
				if (iron_win == 0) iron_win = 1;
				else if (ultron_win == 0 && iron_win == 1 && round2) iron_win = 2;
				else if (ultron_win == 1 && iron_win == 1 && round3) iron_win = 2;
				if (ultron.y == 5){
					ultron_kill_counter++;
					if (ultron_kill_counter >= 13){
						ultron_kill_indx++;
						if (ultron_kill_indx >= 5){
							ultron_kill_indx = 5;
							//game_state = 10;
							if (iron_wins_rate == 0) iron_wins_rate = 1;
							else if (ultrons_win_rate == 0 && iron_wins_rate == 1 && round2) iron_wins_rate = 2;
							else if (ultrons_win_rate == 1 && iron_wins_rate == 1 && round3) iron_wins_rate = 2;
						}
						ultron_kill_counter = 0;
					}
					iShowBMP2(ultron.x, ultron.y, ultron_kill[ultron_kill_indx], 0);
				}
				else if (ultron.y < 5) ultron.y = 5;
				else if (ultron.y >= 5){
					ultron.y -= 5;
					iShowBMP2(ultron.x, ultron.y, "iron_pic\\ultron_flying_down.bmp", 0);
				}

			}  //Ultron's death


			//ultron end

			//Iron Man's start
			if (iron_gain >= 300){
				iShowBMP2(350, 10, "iron_pic\\max_power_on.bmp", 0);
			} // power observtion

			if (iron_health > 0 && right_flying){

				iShowBMP2(run.x, run.y + 100, "iron_pic\\iron_fly.bmp", 0);

				if (iron_health > 0 && flying_counter > 30){
					flying_counter = 0;
					ultrons_shooot_indx = 4;
					right_flying = false;
				}
				flying_counter++; //indicator
			} //right key activation

			else if (iron_health > 0 && left_flying){
				iShowBMP2(run.x, run.y, "iron_pic\\left_flying.bmp", 0);
				if (iron_health > 0 && flying_counter > 30){
					flying_counter = 0;
					left_flying = false;
				}
				flying_counter++;
			}  // left key activation

			else if (up_flying  && iron_health > 0){
				if (up && iron_health > 0)
					iShowBMP2(run.x, run.y, "iron_pic\\flying_up.bmp", 0);
				else if (iron_health > 0 && !up)
					iShowBMP2(run.x, run.y, "iron_pic\\flying_down.bmp", 0);
				if (iron_health > 0 && flying_counter > 30){
					flying_counter = 0;
					up_flying = false;
				}
				flying_counter++;
			} //Upper and down key activation

			else if (max_power && iron_health > 0){
				iShowBMP2(run.x, run.y, max_shot[max_shoot_indx], 0);
				if (iron_health > 0 && lighting_blust){
					if (iron_health > 0 && mx_shootx + run.x + 243 >= ultron.x + 30) mx_shootx = 0;
					while (iron_health > 0 && (mx_shootx + run.x + 243) != ultron.x + 30){
						iShowBMP2(run.x + 243 + mx_shootx, run.y + 190, "iron_pic\\lighting_blust.bmp", 0);
						mx_shootx++;
					}

					if (run.y + 190 > ultron.y && run.y + 190 <= ultron.y + 210){
						ultron_health -= 1000;
						if (ultron_health <= 0) ultron_health = 0;
						iron_gain = 0;
					}

					if (iron_health > 0 && mx_shoot_counter > 2){
						mx_shoot_counter = 0;
						max_shoot_indx = 0;
						lighting_blust = false;
						max_power = false;
					}
					mx_shoot_counter++;
				}
			} //max shot

			else if (iron_health > 0 && iron_shoot){
				iShowBMP2(run.x, run.y, "iron_pic\\iron_shoot.bmp", 0);
				if (iron_health > 0 && shootx + run.x + 277 >= ultron.x + 10)  shootx = 0;
				while (iron_health > 0 && (run.x + shootx + 277) != ultron.x + 10){
					iShowBMP2(run.x + shootx + 277, run.y + 150, shoot_5[0], 0);
					shootx++;
				}

				if (run.y + 190 > ultron.y && run.y + 190 <= ultron.y + 210){
					ultron_health -= 15;
					if (ultron_health <= 0) ultron_health = 0;
					iron_gain += 15;
				}
				if (iron_health > 0 && iron_shoot_counter > 2){
					iron_shoot_counter = 0;
					ultrons_shooot_indx = 0;
					iron_shoot = false;
				}
				iron_shoot_counter++;
			} // Normal shoot

			else if (iron_health > 0 && run.y == 10)
				iShowBMP2(run.x, run.y, "iron_pic\\standing_iron_man.bmp", 0);
			else if (iron_health > 0)
				iShowBMP2(run.x, run.y, "iron_pic\\flying_down.bmp", 0);


			else if (iron_health == 0)
			{
				if (ultron_win == 0) ultron_win = 1;
				//else if (iron_win == 1 && ultron_win == 0) ultron_win = 1;
				else if (iron_win == 0 && ultron_win == 1 && round2) ultron_win = 2;
				else if (iron_win == 1 && ultron_win == 1 && round3) ultron_win = 2;
				if (run.y == 10){
					iron_kill_counter++;
					if (iron_kill_counter >= 15){
						iron_kill_indx++;
						if (iron_kill_indx >= 4){
							iron_kill_indx = 4;
							//game_state = 10;
							if (ultrons_win_rate == 0) ultrons_win_rate = 1;
							else if (iron_wins_rate == 0 && ultrons_win_rate == 1 && round2) ultrons_win_rate = 2;
							else if (iron_wins_rate == 1 && ultrons_win_rate == 1 && round3) ultrons_win_rate = 2;
						}
						iron_kill_counter = 0;
					}
					iShowBMP2(run.x, run.y, iron_kill[iron_kill_indx], 0);
				}
				else if (run.y < 10) run.y = 10;
				else  if (run.y >= 10){
					run.y -= 7;
					iShowBMP2(run.x, run.y, "iron_pic\\flying_down.bmp", 0);
				}

			} //Irons dead

			//Iron Man's End	

			if (iron_wins_rate == 2){
				//You win
				run.x = 50;
				run.y = 10;
				iron_health = 2500;
				iron_kill_indx = 0;
				ultron_shoot = 0;
				ultrons_shooot_indx = 0;
				Doom_shoot_indx = 0;
				level1 = false;
				level2 = true;
				level3 = false;
				round1 = true;
				Doom_dialouge = true;
				iron_wins_rate = 0;
				iron_win = 0;
			}
			else if (ultrons_win_rate == 2){
				iShowBMP(0, 0, "iron_pic\\You_lose.bmp");
				//Game Over
				game_state = 11;
				//ultrons_win_rate = 0;
				round1 = true;
				round2 = false;
				round3 = false;
			}

			if (round1 && iron_wins_rate + ultrons_win_rate == 1){
				round1 = false;
				round2 = true;
				game_state = 10;
			}
			else if (round2 && iron_wins_rate == 1 && ultrons_win_rate == 1){
				round2 = false;
				round3 = true;
				game_state = 10;
			}
		}

		if (!start && !Doom_dialouge && !round1_big && !ultron_dialougue){

			if (round1) iShowBMP2(625, 640, "iron_pic\\Round1_mini.bmp", 0); //round 1 pic
			else if (round2) iShowBMP2(625, 640, "iron_pic\\Round2_mini.bmp", 0); //round 2 pic
			else if (round3) iShowBMP2(625, 640, "iron_pic\\Round3_mini.bmp", 0); //round 3 pic
		}
		if (!start && !round1_big && level1 && !ultron_dialougue){
			if (iron_win == 0 && ultron_win == 0) iShowBMP2(650, 590, "iron_pic\\Score_(0-0).bmp", 0);
			else if (iron_win == 0 && ultron_win == 1) iShowBMP2(650, 590, "iron_pic\\Score_(0-1).bmp", 0);
			else if (iron_win == 0 && ultron_win == 2) iShowBMP2(650, 590, "iron_pic\\Score_(0-2).bmp", 0);
			else if (iron_win == 1 && ultron_win == 0) iShowBMP2(650, 590, "iron_pic\\Score_(1 - 0).bmp", 0);
			else if (iron_win == 1 && ultron_win == 1) iShowBMP2(650, 590, "iron_pic\\Score_(1-1).bmp", 0);       //Only works for level 1
			else if (iron_win == 1 && ultron_win == 2) iShowBMP2(650, 590, "iron_pic\\Score_(1-2).bmp", 0);
			else if (iron_win == 2 && ultron_win == 0) iShowBMP2(650, 590, "iron_pic\\Score_(2-0).bmp", 0);
			else if (iron_win == 2 && ultron_win == 1) iShowBMP2(650, 590, "iron_pic\\Score_(2-1).bmp", 0);
		}

		if (Doom_dialouge){
			iShowBMP(0, 0, Doom_dialouge_pic[Doom_dialougue_indx]);
			Doom_dialougue_counter++;
			if (Doom_dialougue_counter >= 10){
				Doom_dialougue_indx++;
				if (Doom_dialougue_indx >= 6){
					Doom_dialougue_indx = 6;
					Doom_dialouge = false;
				}
				Doom_dialougue_counter = 0;
			}
		}

		//level 2 start
		else if (!Doom_dialouge && !level1 && level2){
			iShowBMP(0, 0, "iron_pic\\level2_BG.bmp"); //level 2 background

			if (iron_health == 0) iron_health_index = 0;
			else if (iron_health > 0 && iron_health <= 750) iron_health_index = 1;
			else if (iron_health > 750 && iron_health <= 1500) iron_health_index = 2;   //Health bar for iron man
			else if (iron_health > 1500 && iron_health <= 2250) iron_health_index = 3;
			else if (iron_health > 2250 && iron_health <= 3000) iron_health_index = 4;

			iShowBMP2(50, 550, iron_health_bar[iron_health_index], 0);

			if (Doom_health == 0) Doom_health_index = 0;
			else if (Doom_health > 0 && Doom_health <= 750) Doom_health_index = 1;
			else if (Doom_health > 750 && Doom_health <= 1500) Doom_health_index = 2;  //Health bar for ultron
			else if (Doom_health > 1500 && Doom_health <= 2250) Doom_health_index = 3;
			else if (Doom_health > 2250 && Doom_health <= 3000) Doom_health_index = 4;

			iShowBMP2(1000, 550, Doom_health_bar[Doom_health_index], 0);

			// Iron man start

			if (iron_gain >= 300){
				iShowBMP2(350, 10, "iron_pic\\max_power_on.bmp", 0); //max power on
			}

			if (iron_health > 0 && right_flying){

				iShowBMP2(run.x, run.y + 100, "iron_pic\\iron_fly.bmp", 0);

				if (iron_health > 0 && flying_counter > 30){
					flying_counter = 0;
					right_flying = false;
				}
				flying_counter++; //indicator
			} //right key activation


			else if (iron_health > 0 && left_flying){
				iShowBMP2(run.x, run.y, "iron_pic\\left_flying.bmp", 0);
				if (iron_health > 0 && flying_counter > 30){
					flying_counter = 0;
					left_flying = false;
				}
				flying_counter++;
			}  // left key activation

			else if (up_flying  && iron_health > 0){
				if (up && iron_health > 0)
					iShowBMP2(run.x, run.y, "iron_pic\\flying_up.bmp", 0);
				else if (iron_health > 0 && !up)
					iShowBMP2(run.x, run.y, "iron_pic\\flying_down.bmp", 0);
				if (iron_health > 0 && flying_counter > 30){
					flying_counter = 0;
					up_flying = false;
				}
				flying_counter++;
			} //Upper and down key activation

			else if (max_power && iron_health > 0){
				iShowBMP2(run.x, run.y, max_shot[max_shoot_indx], 0);
				if (iron_health > 0 && lighting_blust){
					if (iron_health > 0 && mx_shootx + run.x + 243 >= Doom.x + 100) mx_shootx = 0;
					while (iron_health > 0 && (mx_shootx + run.x + 243) != Doom.x + 100){
						iShowBMP2(run.x + 243 + mx_shootx, run.y + 190, "iron_pic\\lighting_blust.bmp", 0);
						mx_shootx++;
					}

					if (run.y + 190 > Doom.y && run.y + 190 <= Doom.y + 210){
						Doom_health -= 1000;
						if (Doom_health <= 0) Doom_health = 0;
						iron_gain = 0;
					}

					if (iron_health > 0 && mx_shoot_counter > 2){
						mx_shoot_counter = 0;
						max_shoot_indx = 0;
						lighting_blust = false;
						max_power = false;
					}
					mx_shoot_counter++;
				}
			} //max shot

			else if (iron_health > 0 && iron_shoot){
				iShowBMP2(run.x, run.y, "iron_pic\\iron_shoot.bmp", 0);
				if (iron_health > 0 && shootx + run.x + 277 >= Doom.x + 100)  shootx = 0;
				while (iron_health > 0 && (run.x + shootx + 277) != Doom.x + 100){
					iShowBMP2(run.x + shootx + 277, run.y + 150, shoot_5[0], 0);
					shootx++;
				}

				if (run.y + 190 > Doom.y && run.y + 190 <= Doom.y + 210){
					Doom_health -= 15;
					if (Doom_health <= 0) Doom_health = 0;
					iron_gain += 15;
				}
				if (iron_health > 0 && iron_shoot_counter > 2){
					iron_shoot_counter = 0;
					ultrons_shooot_indx = 0;//same for doom
					iron_shoot = false;
				}
				iron_shoot_counter++;
			} // Normal shoot

			else if (iron_health > 0 && run.y == 10)
				iShowBMP2(run.x, run.y, "iron_pic\\standing_iron_man.bmp", 0);
			else if (iron_health > 0)
				iShowBMP2(run.x, run.y, "iron_pic\\flying_down.bmp", 0);


			else if (iron_health == 0)
			{
				if (run.y == 10){
					iron_kill_counter++;
					if (iron_kill_counter >= 15){
						iron_kill_indx++;
						if (iron_kill_indx >= 4){
							iron_kill_indx = 4;
							//game_state = 10; // round big pic set up
							if (Dooms_win_rate == 0) Dooms_win_rate = 1;
							else if (iron_wins_rate == 0 && Dooms_win_rate == 1 && round2) Dooms_win_rate = 2;
							else if (iron_wins_rate == 1 && Dooms_win_rate == 1 && round3) Dooms_win_rate = 2;
						}
						iron_kill_counter = 0;
					}
					iShowBMP2(run.x, run.y, iron_kill[iron_kill_indx], 0);
				}
				else if (run.y < 10) run.y = 10;
				else  if (run.y >= 10){
					run.y -= 7;
					iShowBMP2(run.x, run.y, "iron_pic\\flying_down.bmp", 0);
				}
			  
				

			}
			// Iron man end

			// Doom start

			Doom_counter++;
			if (Doom_health > 0 && Doom_counter <= 250)
			{
				if (Doom_health > 0 && Doom_counter <= 30)  iShowBMP2(Doom.x, Doom.y, "iron_pic\\Doom_stand_1.bmp", 0); //Doom stand on ground 

				else if (Doom_health > 0 && run.y <= 218 && Doom_counter > 30 && Doom_counter <= 65) iShowBMP2(Doom.x, Doom.y, "iron_pic\\doom_fire_prep.bmp", 0); //run.y indicates the vertical position of iron man 
				else if (Doom_health > 0 && run.y <= 218 && Doom_counter > 65 && Doom_counter <= 85) iShowBMP2(Doom.x, Doom.y, "iron_pic\\doom_fire_prep_2.bmp", 0);


				else if (Doom_health > 0 && run.y <= 218 && Doom_counter > 85 && Doom_counter <= 200){

					iShowBMP2(Doom.x, Doom.y, Doom_ground_shoot[Doom_ground_shoot_indx], 0);

					Doom_shoot_indx_counter++;
					if (Doom_shoot_indx_counter > 1){
						Doom_shoot_indx_counter = 0;
						Doom_ground_shoot_indx++;
						if (Doom_ground_shoot_indx >= 4) Doom_ground_shoot_indx = 0;
					}


					if (Doom_health > 0 && Doom.x - ultron_shoot - 50 <= run.x + ultrons_shoot_point[ultrons_shooot_indx]){
						ultron_shoot = 0;
					}
					Doom_counter++;
					while (Doom_health > 0 && Doom.x - ultron_shoot >= run.x + ultrons_shoot_point[ultrons_shooot_indx]){//notice
						iShowBMP2(Doom.x - ultron_shoot - 5, Doom.y + 195, "iron_pic\\Doom_blust_2.bmp", 0);  //changeable
						ultron_shoot += 30;
					}

					iron_health -= 25;
					if (iron_health <= 0) iron_health = 0;
				}
				else if (Doom_health > 0 && Doom_counter > 200) iShowBMP2(Doom.x, Doom.y, "iron_pic\\Doom_stand_1.bmp", 0);

				else  iShowBMP2(Doom.x, Doom.y, "iron_pic\\Doom_stand_1.bmp", 0);
			}   // Doom shoot on ground


			else if (Doom_health > 0 && Doom_counter > 250 && Doom_counter <= 340)
			{
				Doom.y += 5;
				if (Doom.y >= 330) Doom.y = 330;
				if (Doom.y >= ultron_lim) Doom.y = ultron_lim;
				iShowBMP2(Doom.x + 50, Doom.y, Doom_flying_up[Doom_flying_indx], 0);
				Doom_flying_indx_counter++;
				if (Doom_flying_indx_counter > 2){
					Doom_flying_indx_counter = 0;
					Doom_flying_indx++;
					if (Doom_flying_indx > 2) Doom_flying_indx = 0;
				}
			} // Doom is flying up


			else if (Doom_health > 0 && Doom_counter > 340 && Doom_counter <= 500){

				if (Doom_health > 0 && Doom.y + 130 <= run.y + 150 && Doom.y+130>=run.y+20){ //edit available on this line(50)
					Doom_shoot_func();
				}//edit

				else{
					Doom_float_func();
				}

			} //Doom float on air and fighting

			else if (Doom_health > 0 && Doom_counter > 500 && Doom_counter <= 600){
				Doom.x -= 5;
				iShowBMP2(Doom.x, Doom.y, Doom_flying_left[Doom_left_fly_indx], 0);
				Doom_left_fly_counter++;
				if (Doom_left_fly_counter > 5){
					Doom_left_fly_counter = 0;
					Doom_left_fly_indx++;
					if (Doom_left_fly_indx > 2) Doom_left_fly_indx = 0;
				}
			} //Doom left fly

			else if (Doom_health > 0 && Doom_counter > 600 && Doom_counter <= 750){
				if (Doom_health > 0 && Doom.y + 130 <= run.y + 150 && Doom.y + 130 >= run.y + 20){ //edit available on this line
					Doom_shoot_func();
				}//edit

				else{
					Doom_float_func();
				}
			} //Doom float on air and fighting

			else if (Doom_health > 0 && Doom_counter > 750 && Doom_counter <= 800){
				iShowBMP2(Doom.x, Doom.y, Doom_float[Doom_float_indx], 0);

				Doom_float_indx_counter++;
				if (Doom_float_indx_counter > 5){
					Doom_float_indx_counter = 0;
					Doom_float_indx++;
					if (Doom_float_indx > 2) Doom_float_indx = 1;
				}

				Doom.y -= 5;
			} // Doom flying down

			else if (Doom_health > 0 && Doom_counter > 800 && Doom_counter <= 950){
				if (Doom_health > 0 && Doom.y + 130 <= run.y + 150 && Doom.y + 130 >= run.y + 20){ //edit available on this line
					Doom_shoot_func();
				}//edit

				else{
					Doom_float_func();
				}
			}// Doom floating on air && fighting

			else if (Doom_health > 0 && Doom_counter > 950 && Doom_counter <= 1100){
				Doom.x += 5;
				if (Doom.x == 1150){
					Doom_counter = 1100; //Using Technique
				}
				Doom.y += 3;
				iShowBMP2(Doom.x, Doom.y, Doom_flying_right[Doom_right_fly_indx], 0);
				Doom_right_fly_counter++;
				if (Doom_right_fly_counter > 5){ 
					Doom_right_fly_counter = 0;
					Doom_right_fly_indx++;
					if (Doom_right_fly_indx > 2) Doom_right_fly_indx = 0;
				}
			}//Doom's move horizontally and vertically

			else if (Doom_health > 0 && Doom_counter > 1100 && Doom_counter <= 1250){
				if (Doom_health > 0 && Doom.y + 130 <= run.y + 150 && Doom.y + 130 >= run.y + 20){ //edit available on this line
					Doom_shoot_func();
				}//edit

				else{
					Doom_float_func();
				}
			}

			else if (Doom_health > 0 && Doom_counter > 1250){
				Doom.y -= 5;
				if (Doom.y <= 5){
					Doom_counter = 0;
				}
				iShowBMP2(Doom.x, Doom.y, Doom_float[Doom_float_indx], 0);

				Doom_float_indx_counter++;
				if (Doom_float_indx_counter > 5){
					Doom_float_indx_counter = 0;
					Doom_float_indx++;
					if (Doom_float_indx > 2) Doom_float_indx = 1;
				}
			}//Doom flying down

			else if (Doom_health == 0){
				
				if (Doom.y == 5){
					Doom_kill_counter++;
					if (Doom_kill_counter >= 13){
					Doom_kill_indx++;                        //edit kora lagbo
					if (Doom_kill_indx >= 3){ 
					Doom_kill_indx = 3;
					//game_state = 10;// lagbe na
					if (iron_wins_rate == 0) iron_wins_rate = 1;
					else if (Dooms_win_rate == 0 && iron_wins_rate == 1 && round2) iron_wins_rate = 2;
					else if (Dooms_win_rate == 1 && iron_wins_rate == 1 && round3) iron_wins_rate = 2;
					}
					Doom_kill_counter = 0;
					}
					iShowBMP2(Doom.x, Doom.y, Doom_kill[Doom_kill_indx], 0);
				}
				else if (Doom.y < 5) Doom.y = 5;
				else if (Doom.y >= 5){
					Doom.y -= 5;
					Doom_falling_counter++;
					if (Doom_falling_counter > 2){
						Doom_falling_indx++;                                  // edit
						if (Doom_falling_indx >= 4) Doom_falling_indx = 4;
					}
					iShowBMP2(Doom.x, Doom.y, Doom_falling_down[Doom_falling_indx], 0);
				}

			}  //Doom's death

			//Doom end

			if (iron_wins_rate == 2){
				win_counter++;
				//You win
				/*run.x = 50;
				run.y = 10;
				iron_health = 2500;
				iron_kill_indx = 0;
				ultron_shoot = 0;
				ultrons_shooot_indx = 0;
				Doom_shoot_indx = 0;
				level1 = false;
				level2 = false; 
				level3 = true;
				
				iron_wins_rate = 0;
				iron_win = 0;
				*/
				round1 = false;
				round2 = false;
				round3 = false;
				if(win_counter>=0 && win_counter<=60) iShowBMP(0, 0, "iron_pic\\You_win.bmp");
				else iShowBMP(0, 0, "iron_pic\\Congratulations.bmp");
			}
			else if (Dooms_win_rate == 2){
				iShowBMP(0, 0, "iron_pic\\You_lose.bmp");
				//Game Over
				game_state = 11;
				//ultrons_win_rate = 0;
				round1 = true;
				round2 = false;
				round3 = false;
			}

			if (round1 && iron_wins_rate + Dooms_win_rate == 1){
				round1 = false;
				round2 = true;
				game_state = 10;
			}
			else if (round2 && iron_wins_rate == 1 && Dooms_win_rate == 1){
				round2 = false;
				round3 = true;
				game_state = 10;
			}

			

				if (round1) iShowBMP2(625, 640, "iron_pic\\Round1_mini.bmp", 0); //round 1 pic
				else if (round2) iShowBMP2(625, 640, "iron_pic\\Round2_mini.bmp", 0); //round 2 pic
				else if (round3) iShowBMP2(625, 640, "iron_pic\\Round3_mini.bmp", 0); //round 3 pic
			

				
				if (iron_wins_rate == 0 && Dooms_win_rate == 0) iShowBMP2(650, 590, "iron_pic\\Score_(0-0).bmp", 0);
				else if (iron_wins_rate == 0 && Dooms_win_rate == 1) iShowBMP2(650, 590, "iron_pic\\Score_(0-1).bmp", 0);
				//else if (iron_wins_rate == 0 && Dooms_win_rate == 2) iShowBMP2(650, 590, "iron_pic\\Score_(0-2).bmp", 0); //problem at this line
				else if (iron_wins_rate == 1 && Dooms_win_rate == 0) iShowBMP2(650, 590, "iron_pic\\Score_(1 - 0).bmp", 0);
				else if (iron_wins_rate == 1 && Dooms_win_rate == 1) iShowBMP2(650, 590, "iron_pic\\Score_(1-1).bmp", 0);       //Only works for level 2
				//else if (iron_wins_rate == 1 && Dooms_win_rate == 2) iShowBMP2(650, 590, "iron_pic\\Score_(1-2).bmp", 0);
				//else if (iron_wins_rate == 2 && Dooms_win_rate == 0) iShowBMP2(650, 590, "iron_pic\\Score_(2-0).bmp", 0);
				//else if (iron_wins_rate && Dooms_win_rate == 1) iShowBMP2(650, 590, "iron_pic\\Score_(2-1).bmp", 0);
				
		}
	}

		
		



	

	else if (game_state == 1){
		iShowBMP(0,0,"iron_pic\\Instructions_in.bmp");
		iShowBMP2(1270, 620, "iron_pic\\Back.bmp", 0);
	}

	else if (game_state == 2){
		iShowBMP(0, 0, "iron_pic\\MainMenu.bmp");
		iShowBMP2(1270, 620, "iron_pic\\Back.bmp", 0);
		iShowBMP2(350, 320, "iron_pic\\Sound.bmp", 0);
		iShowBMP2(200, 200, "iron_pic\\on.bmp", 0);  //change korsi
		iShowBMP2(500, 200, "iron_pic\\off.bmp", 0);
	}

	else if (game_state == 3){
		iShowBMP(0, 0, "iron_pic\\About_in.bmp");
		iShowBMP2(1270, 620, "iron_pic\\Back.bmp", 0);
	}
}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (game_state != -1 && mx >= 1270 && mx <= 1470 && my >= 620 && my <= 732) game_state = -1;
		else if(game_state==-1){
			for (int i = 0; i < 4; i++){
				if (mx >= mn_button_pos[i].x && mx <= mn_button_pos[i].x + menu_buttonx[i] && my >= mn_button_pos[i].y && my <= mn_button_pos[i].y + 113){
					game_state = i;
				}
			}
		}

		if (game_state == 2 && mx >= 200 && mx <= 450 && my >= 200 && my <= 340){
			if (!music){
				music = true;
				PlaySound("iron_music\\Portals(wav).wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}

		else if (game_state == 2 && mx >= 500 && mx <= 750 && my >= 200 && my <= 340){
			if (music){
				music = false;
				PlaySound(0, 0, 0);
			}
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
	}
}


void iPassiveMouseMove(int mx,int my)
{
	

 mposx = mx;
 mposy = my;
 if(mx== 2){}       
 else if(my== 2){}  

}


void iKeyboard(unsigned char key)
{
	if(key == 'a')
	{
		if (key_5_counter >= 2){

			if (iron_health > 0){
				iron_shoot = true;
				shootx = 0;
				ultrons_shooot_indx = 5;
				iron_shoot_counter = 0;
			}
			key_5_counter = 0;
		}
		key_5_counter++;
	}
	else if (key == 'd'){
		if (!max_power && iron_health>0 && iron_gain>=300){
			max_power = true;
			iron_gain = 0;
		}
	}
	
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_RIGHT)
	{
		if (iron_health > 0){
			right_flying = true;
			left_flying = false;
			up_flying = false;
			ultrons_shooot_indx = 3;
			flying_counter = 0;
			run.x += 10;
			if (run.x >= 1329) run.x = 1329;
		}
	}
	else if (key == GLUT_KEY_LEFT){
		if (iron_health > 0){
			left_flying = true;
			right_flying = false;
			up_flying = false;
			ultrons_shooot_indx = 4;
			flying_counter = 0;
			run.x -= 5;
			if (run.x <= 0) run.x = 0;
		}
	}
	else if (key == GLUT_KEY_UP){
		if (iron_health > 0){
			up_flying = true;
			up = true;
			right_flying = false;
			left_flying = false;
			ultrons_shooot_indx = 2;
			flying_counter = 0;
			run.y += 7;
			if (run.y >= 330) run.y = 330;
		}
	}
	else if (key == GLUT_KEY_DOWN){
		if (iron_health > 0){
			if (run.y > 10){
				up_flying = true;
				up = false;
				right_flying = false;
				left_flying = false;
				ultrons_shooot_indx = 1;
				flying_counter = 0;
				run.y -= 7;
			}
			if (run.y <= 10) run.y = 10;
		}
	}	
}

void max_form(){
	if (iron_health>0 && max_power && game_state == 0){
		max_shoot_indx++;
		if (max_shoot_indx >= 5){
			max_shoot_indx = 5;
			lighting_blust = true;
		}
	}
}


int main()
{
	iSetTimer(180, max_form);
	if (music){
		PlaySound("iron_music\\Portals(wav).wav", NULL, SND_LOOP | SND_ASYNC);
	}
	int menu_sum = 70;
	for (int i = 3; i >= 0; i--){
		mn_button_pos[i].x = 100;
		mn_button_pos[i].y = menu_sum;
		menu_sum += 100;
	}
	iInitialize(width, height, "IRON MAN");  // Setting the gaming window
	return 0;
}
