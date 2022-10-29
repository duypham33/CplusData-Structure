
/*

    This file is to establish the definitions for all programmer-defined functions of Game class, aside from main ()

*/

#include "Game.h"

//Five test cases are going to go with the user direction of how to play
//An array of test cases
const string TestCase[5] = { "The test case for the main character's movement, ",
                            "The test case for shooting sphere bullet, ",
                            "The test case for taking skill gift sphere, ",
                            "The test case for taking new bullet gift, ",
                            "The test case for taking HP gift, " 
                           };


//Default constructor
Game::Game()
{
    //Allocate space for the main object
    this->ship = new MainObject(MAIN_OBJECT_WIDTH, MAIN_OBJECT_HEIGHT);
    this->ship->SetRect(START_XPOS, START_YPOS);
}

//Destructor
Game::~Game()
{
    //Free up the space
    delete this->ship;
}


//This function runs the whole a game
int Game::run()
{
    // Initialize SDL modes (library SDL, Window Screen Mode, font text mode, and audio mode)
    if (!this->Init())
        return 0;

    //Load main object (Space ship)    
    bool ret = ship->LoadImg("Ship3.png", true, 255);
    if (!ret)
        return 0;

    //Initialize exhaust object for the ship
    Clip* exhaust = new Clip(EXHAUST_WIDTH, EXHAUST_HEIGHT, EXHAUST_CLIPS_NUMS, Clip::VERTICAL);
    ret = exhaust->LoadImg("exhaustV.png", true, 255);
    if (!ret)
        return 0;

    //Initialize explosion object for threats
    Clip* explo = new Clip(EXPLO_WIDTH, EXPLO_HEIGHT, THREAT_EXPLO_NUMS);
    ret = explo->LoadImg("explo.png", true, 0);
    if (!ret)
        return 0;

    //Initialize explosion object for the main object
    Clip* mExplo = new Clip(MAIN_EXPLO_SIZE, MAIN_EXPLO_SIZE, MAIN_EXPLO_NUMS);
    ret = mExplo->LoadImg("mainExplo.png", true, 0);
    if (!ret)
        return 0;

    //Load the font for displaying the game result
    TTF_Font* font1 = TTF_OpenFont("times new roman.ttf", 50);
    TTF_Font* font2 = TTF_OpenFont("times new roman.ttf", 25);
    if (!font1 || !font2)
        return 0;

    TextObject* resultText = new TextObject(SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2 - 75, "");
    TextObject* scoreText = new TextObject(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 5, "");
    TextObject* returnText = new TextObject(SCREEN_WIDTH / 2 - 130, SCREEN_HEIGHT / 2 + 55, "RETURN MAIN MENU");
    bool displayResult = false;
    bool win = false;

    //An array of file names of the multiple bullets
    const char* file_names[5] = { "double1.png",  "double2.png", "double3.png", "double4.png", "double5.png" };
    int menu_opt = 0;

    do    //The main loop for the game windown
    {      
        //Resets necessary static variables for one game(Because we have a loop for game, so it is needed to reset them every loop)
        if (!this->reset(displayResult, win))
            return 0;

        //Load the game menu
        menu_opt = this->showMenu(screen, menu_font_text);
        if (menu_opt == -1)
            return 0;

        else if (menu_opt == 1)    //Tutorial option
        {
            int opt = this->tutorial(screen);
            if (opt == -1)
                return 0;
            
            if (opt == 2)
                menu_opt = 2;   //The same with exit feature
        }

        else if (menu_opt == 0)   //Play option
        {            
            //Initialize objects and necessary variables
            
            //Make threats
            srand(time(NULL));
            vector<ThreatObject*> pThreats;
            for (int it = 0; it < NUM_THREATS; it++)
            {
                ThreatObject* pThr = new ThreatObject();
                int startPos_x = (it < NUM_THREATS / 2) ? SCREEN_WIDTH * 0.25 : SCREEN_WIDTH * 0.7;
                pThr->SetRect(startPos_x, -1000 - 400 * (it % (NUM_THREATS / 2)));
                ret = pThr->LoadImg("chicken.png", true, 255);
                if (!ret)
                    return 0;
                pThr->InitBullet();
                pThreats.push_back(pThr);
            }

            //Necessary variables
            int bg_y = 0;
            int bgCount = 0;
            int frameExh = 0, frameExplo = 0, frameMExplo = 0, frameDam = 0;
            bool isExplo = false;
            bool isMExplo = false;
            bool isDamaged = false;
            int numsDie = 0;
            int Round = 1;
            int changeRound = 0;

            //Pointers to the gifts (They have the same type with Bullet)
            Bullet* skillGift_ptr = NULL;
            Bullet* bulGift_ptr = NULL;
            Bullet* hp_ptr = new Bullet;
            if (hp_ptr)
            {
                hp_ptr->setWidthHeight(55, 46);
                hp_ptr->LoadImg("heart.png", true, 0);
            }

            int skillMoment = NUM_THREATS - (rand() % 10 + 10);
            int newBulletMomt = -1;
            bool tookSkill = false;
            bool newBullet = false;
            bool hpFlag = false;

            //Pointer to a TextObject for the main object's HP
            TextObject* pMainHP = new TextObject(17, 11, "100");
            BaseObject* pHeart = new Bullet;
            pHeart->LoadImg("heart.png", true, 0);

            //Pointer to a TextObject for the main object's score
            TextObject* pScore = new TextObject(10, SCREEN_HEIGHT - 30, "SCORE");
            pScore->setColor(TextObject::GREEN);
            int score = 0;
            displayResult = false;
            win = false;
                                
            SDL_GetMouseState(&MOUSE_X, &MOUSE_Y);
            bool running = true;  //Flag for running the game or quit 
            //Play game
            while (running)    //The loop for playing game
            {
                while (SDL_PollEvent(&g_even))     //Loop for getting events
                {
                    if (g_even.type == SDL_QUIT)
                    {
                        running = false;                        
                        break;
                    }

                    if (g_even.type == SDL_MOUSEBUTTONDOWN && g_even.button.button == SDL_BUTTON_LEFT)
                    {
                        if (!(displayResult && !win))   //Still not lost
                        {
                            //Make bullet
                            Bullet* bll_ptr = new Bullet;
                            bll_ptr->setWidthHeight(BULLET_WIDTH, BULLET_HEIGHT);
                            bll_ptr->LoadImg("Sphere Bullet.png", true, 255);
                            bll_ptr->setIsMove(true);
                            bll_ptr->SetRect(ship->GetRect().x + ship->GetRect().w / 2 - 10, ship->GetRect().y + 5);
                            Mix_PlayChannel(-1, BULLET_SOUND, 0);

                            BulletList.push_back(bll_ptr);  //Add a new bullet element into the array   
                        }


                        //Check whether return-menu button is selected or not
                        if (displayResult)
                        {
                            MOUSE_X = g_even.motion.x;
                            MOUSE_Y = g_even.motion.y;
                            //Check whether a return menu option is focused or not
                            if (MOUSE_X >= returnText->GetRect().x && MOUSE_X <= returnText->GetRect().x + returnText->GetRect().w
                                && MOUSE_Y >= returnText->GetRect().y && MOUSE_Y <= returnText->GetRect().y + returnText->GetRect().h)                               
                                running = false;   //Return the main menu
                        }
                    }


                    else if (g_even.type == SDL_MOUSEBUTTONDOWN && g_even.button.button == SDL_BUTTON_RIGHT && newBullet)
                    {
                        if (!(displayResult && !win))    //Still not lost
                        {
                            for (int i = 0; i < 5; i++)
                            {
                                Bullet* bll_ptr = new Bullet((Bullet::BulletDir)(i / 1.5));
                                bll_ptr->setWidthHeight(63, 63);
                                bll_ptr->LoadImg(file_names[i], true, 0);
                                bll_ptr->setIsMove(true);
                                bll_ptr->SetRect(ship->GetRect().x + ship->GetRect().w / 2 + 32 * (i - 3), ship->GetRect().y - 40);
                                BulletList.push_back(bll_ptr);  //Add a new bullet element into the array 
                            }

                            Mix_PlayChannel(-1, BULLET_SOUND, 0);
                        }
                    }


                    else if (g_even.type == SDL_MOUSEMOTION && displayResult)
                    {
                        MOUSE_X = g_even.motion.x;
                        MOUSE_Y = g_even.motion.y;
                        //Check whether a return menu option is focused or not
                        if (MOUSE_X >= returnText->GetRect().x && MOUSE_X <= returnText->GetRect().x + returnText->GetRect().w
                            && MOUSE_Y >= returnText->GetRect().y && MOUSE_Y <= returnText->GetRect().y + returnText->GetRect().h)
                            returnText->setColor(TextObject::WHITE);
                        else
                            returnText->setColor((win) ? TextObject::GREEN : TextObject::RED);
                    }

                    if (!(displayResult && !win))
                        ship->HandleMove(g_even);
                }

                //Apply background
                if (bgCount == 10)   //Used to delay background moving
                {
                    bg_y += 1;
                    bgCount = 0;
                }
                bgCount++;

                SDLCommonFunc::ApplySurface(bkground, screen, 0, bg_y);
                SDLCommonFunc::ApplySurface(bkground, screen, 0, bg_y - SCREEN_HEIGHT);
                if (bg_y >= SCREEN_HEIGHT)
                    bg_y = 0;

                //Show the main object, its exhaust and bullets
                if (!(displayResult && !win))    //If the main object is still not lost yet, display them
                {
                    //Show the main object out the screen
                    ship->Show(screen);

                    //Display the exhaust for the ship
                    this->makeExhaust(exhaust, frameExh);

                    //Make bullet for the main object
                    this->makeBullet();

                    //Display the main object being damaged as hit some threats or their bullets
                    this->damagedShip(isDamaged, frameDam);
                }
                               
                //Handle threats move and collision with the main object and bullets
                this->threatsActions(pThreats, Round, isDamaged, pMainHP, numsDie, score, pScore, isExplo, explo, skillMoment, skillGift_ptr,
                    newBulletMomt, bulGift_ptr);

                //Display the explosion as some threat dies
                this->makeThreatExplo(explo, isExplo, frameExplo);

                //This function displays the explosion as the main object lost
                this->makeMainExplo(mExplo, isMExplo, frameMExplo);
               
                //Display the skill gift
                this->skillGift(skillGift_ptr, tookSkill);

                //Display the new bullet gift
                this->bulletGift(bulGift_ptr, newBullet, tookSkill);

                //Check for the HP gift and Display the hp gift
                this->hpGift(hp_ptr, hpFlag, pMainHP, 100000);    //The probability of HP gift is 0.001% every moment

                //Show the remaining main object's HP
                pHeart->Show(screen);
                pMainHP->Show(screen, g_font_text);
                //Show the score
                pScore->Show(screen, g_font_text);

                //Check whether the threats are all died or not, to move on the next round
                if (NUM_THREATS < 1)
                {
                    changeRound++;
                    if (changeRound >= 2000)
                    {
                        changeRound = 0;
                        Round++;
                        if (Round == 2)   //Create threats for the second round 
                        {
                            NUM_THREATS = 50;
                            SPEED *= 4;         //Increase the threat's speed
                            THREAT_HP *= 2;     //Increase the threat's HP
                            BULLET_SPEED++;     //Increase the threat's bullet speed
                            THREAT_ATTACK++;    //Increase attack level
                            for (int it = 0; it < NUM_THREATS; it++)
                            {
                                ThreatObject* pThr = new ThreatObject(THREAT2_WIDTH, THREAT2_HEIGHT, SPEED, THREAT_HP);
                                int startPos_x = (it < NUM_THREATS / 2) ? SCREEN_WIDTH * 0.25 : SCREEN_WIDTH * 0.7;
                                pThr->SetRect(startPos_x, -5 - 400 * (it % (NUM_THREATS / 2)));
                                ret = pThr->LoadImg("Bird.png", true, 0);
                                if (!ret)
                                    return 0;
                                pThr->InitBullet(LASER_WIDTH, LASER_HEIGHT);
                                pThreats.push_back(pThr);
                            }
                            //Set randomly for when new bullet gift and skill gift happen                  
                            newBulletMomt = NUM_THREATS - (rand() % 6 + 5);
                            skillMoment = NUM_THREATS / 2;
                            delete skillGift_ptr;
                            skillGift_ptr = NULL;
                        }

                        else if (Round == 3)   //Create threats for the final round 
                        {
                            NUM_THREATS = 2;
                            SPEED *= 2;          //Increase the threat's speed
                            THREAT_HP = 1000;    //Increase the threat's HP                   
                            RECHARGE_TIME = 15;  //Decrease recharge time for bullet
                            THREAT_ATTACK += 3;    //Increase attack level
                            for (int it = 0; it < NUM_THREATS; it++)
                            {
                                ThreatObject* pThr = new ThreatObject((it == 0) ? XMAS_BOSS_WIDTH : BOSS_WIDTH,
                                    (it == 0) ? XMAS_BOSS_HEIGHT : BOSS_HEIGHT, SPEED, THREAT_HP);
                                int startPos_x = (it < NUM_THREATS / 2) ? SCREEN_WIDTH * 0.1 : SCREEN_WIDTH * 0.7;
                                pThr->SetRect(startPos_x, -5 - 400 * (it % (NUM_THREATS / 2)));
                                if (it == 0)
                                    ret = pThr->LoadImg("Xmas chicken.png", true, 255);
                                else
                                    ret = pThr->LoadImg("boss.png", true, 0);
                                if (!ret)
                                    return 0;
                                pThr->InitBullet(BLUE_LASER_WIDTH, BLUE_LASER_HEIGHT);
                                pThreats.push_back(pThr);
                            }
                        }
                    }
                }


                //Check the game result and display if it should
                this->result(displayResult, Round, win, mExplo, isMExplo, score, resultText, scoreText, returnText, font1, font2);
                
                //Update the screen     
                if (SDL_Flip(screen) == -1)
                    return 0;
            }


            //Free spaces
            pThreats.clear();
            BulletList.clear();
            delete skillGift_ptr;
            delete bulGift_ptr;
            delete hp_ptr;
            delete pMainHP;
            delete pHeart;
            delete pScore;
        }

    } while (menu_opt != 2);
    

    //Free Mixer
    Mix_FreeChunk(BULLET_SOUND);
    Mix_FreeChunk(EXPLO_SOUND);
    Mix_FreeChunk(CHICKEN_SOUND);
    Mix_FreeChunk(DAMAGED_SOUND);
    Mix_FreeChunk(VICTORY_SOUND);
    //Mix_FreeMusic();
    Mix_CloseAudio();

    //Free spaces
    delete exhaust;
    delete explo;
    delete mExplo;
    delete resultText;
    delete scoreText;
    delete returnText;

    //Clean the screen
    SDLCommonFunc::CleanUp(screen, bkground);
    SDL_Quit();

    return 1;    //The program was successfull
}







//////////////////////////////////////// Private Function \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	
// Initialize SDL modes (library SDL, Window Screen Mode, font text mode, and audio mode)
bool Game::Init()
{
    //Initialize the library SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return false;

    //Set Window Screen Mode
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
        return false;

    //Set font text mode
    if (TTF_Init() == -1)
        return false;
    g_font_text = TTF_OpenFont("ARCADECLASSIC.TTF", 20);
    if (!g_font_text)
        return false;

    //Open audio mode
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        return false;

    //Read audio files
    CHICKEN_SOUND = Mix_LoadWAV("chik.wav");
    EXPLO_SOUND = Mix_LoadWAV("laser explosion.wav");
    BULLET_SOUND = Mix_LoadWAV("shoot1.wav");
    DAMAGED_SOUND = Mix_LoadWAV("dam.wav");
    VICTORY_SOUND = Mix_LoadWAV("victory.wav");

    if (!CHICKEN_SOUND || !EXPLO_SOUND || !BULLET_SOUND || !DAMAGED_SOUND || !VICTORY_SOUND)
        return false;

    //Load Background
    bkground = SDLCommonFunc::LoadImage("bkgr.png", false, 0);
    if (bkground == NULL)
        return false;

    //Set caption for the windown
    SDL_WM_SetCaption("Chicken Invaders", "");

    return true;
}


// Display game menu and return a menu option got from the user
int Game::showMenu(SDL_Surface* des, TTF_Font* font)
{
    //Load the menu image
    g_menu = SDLCommonFunc::LoadImage("menu.png", false, 0);
    if (!g_menu)
        return -1;
    //Load the menu font
    font = TTF_OpenFont("ARCADECLASSIC.TTF", 30);
    if (!font)
        return -1;

    const int numItems = 3;    //Options of menu
    SDL_Rect posArr[numItems];
    posArr[0].x = 350;
    posArr[0].y = 380;
    posArr[1].x = 350;
    posArr[1].y = 430;
    posArr[2].x = 350;
    posArr[2].y = 480;

    TextObject* textOpt[numItems] = { nullptr };
    textOpt[0] = new TextObject(posArr[0].x, posArr[0].y, "PLAY GAME");
    textOpt[0]->setColor(TextObject::RED);
    textOpt[1] = new TextObject(posArr[1].x, posArr[1].y, "TUTORIAL");
    textOpt[1]->setColor(TextObject::RED);
    textOpt[2] = new TextObject(posArr[2].x, posArr[2].y, "EXIT");
    textOpt[2]->setColor(TextObject::RED);

    SDL_Event events;
    while (true)
    {
        //Apply surface for menu image
        SDLCommonFunc::ApplySurface(g_menu, des, 0, 0);
        //Show text for menu options
        for (int i = 0; i < numItems; i++)
        {
            textOpt[i]->Show(des, font);
        }

        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
                return 2;   //The same with Exit option
            else if (events.type == SDL_MOUSEMOTION)
            {
                MOUSE_X = events.motion.x;
                MOUSE_Y = events.motion.y;
                //Check whether a menu option is focused or not
                for (int i = 0; i < numItems; i++)
                {
                    if (MOUSE_X >= textOpt[i]->GetRect().x && MOUSE_X <= textOpt[i]->GetRect().x + textOpt[i]->GetRect().w
                        && MOUSE_Y >= textOpt[i]->GetRect().y && MOUSE_Y <= textOpt[i]->GetRect().y + textOpt[i]->GetRect().h)
                        textOpt[i]->setColor(TextObject::GREEN);
                    else
                        textOpt[i]->setColor(TextObject::RED);
                }
            }

            else if (events.type == SDL_MOUSEBUTTONDOWN)
            {
                MOUSE_X = events.motion.x;
                MOUSE_Y = events.motion.y;
                //Check whether a menu option is focused or not
                for (int i = 0; i < numItems; i++)
                {
                    if (MOUSE_X >= textOpt[i]->GetRect().x && MOUSE_X <= textOpt[i]->GetRect().x + textOpt[i]->GetRect().w
                        && MOUSE_Y >= textOpt[i]->GetRect().y && MOUSE_Y <= textOpt[i]->GetRect().y + textOpt[i]->GetRect().h)
                        return i;   //Return the option number chosen
                }
            }
        }

        //Update the screen     
        SDL_Flip(des);
    }

    return -1;
}


//Display the exhaust for the ship (main object)
void Game::makeExhaust(Clip* exhaust, int& frameExh)
{
    if (exhaust)
    {
        exhaust->setFrame(frameExh);
        int exhPosx = ship->GetRect().x + 18;
        int exhPosy = ship->GetRect().y + MAIN_OBJECT_HEIGHT - 5;
        exhaust->SetRect(exhPosx, exhPosy);
        exhaust->Show(screen, nullptr, 50);
        frameExh++;
        if (frameExh >= EXHAUST_CLIPS_NUMS * 50)
            frameExh = 0;
    }
}

//Make the bullet for the ship (main object)
void Game::makeBullet()
{
    for (int ib = 0; ib < BulletList.size(); ib++)
    {
        if (ib < BulletList.size())
        {
            Bullet* bllPtr = BulletList[ib];
            if (bllPtr)
            {
                if (bllPtr->getIsMove())
                {
                    bllPtr->Show(screen);
                    int n = (ib == 0 || ib == 4) ? 1 : 4;
                    bllPtr->HandleMove(1, BULLET_MAIN_SPEED, SCREEN_WIDTH, SCREEN_HEIGHT, n);
                }
                else
                {
                    BulletList.erase(BulletList.begin() + ib);  //Remove the bullet when it has gone out the screen
                    delete bllPtr;   //Free up the memory
                    bllPtr = NULL;
                }
            }
        }
    }
}



//This function handles threats move and collision with the main object and bullets
void Game::threatsActions(vector<ThreatObject*>& pThreats, int& Round, bool& isDamaged, TextObject*& pMainHP, int& numsDie, int& score,
    TextObject*& pScore, bool& isExplo, Clip*& explo, int& skillMoment, Bullet*& skillGift_ptr, int& newBulletMomt, Bullet*& bulGift_ptr)
{
    int borderY = (Round == 3) ? SCREEN_HEIGHT * 0.55 : SCREEN_HEIGHT * 0.35;
    //Handle threats move and collision with the main object and bullets
    for (int i = 0; i < pThreats.size(); i++)
    {
        if (i >= 0 && i < NUM_THREATS)
        {
            pThreats[i]->moveSteps();
            pThreats[i]->HandleMove(SCREEN_WIDTH, borderY);
            pThreats[i]->Show(screen);

            //Make egg as bullets for the threat objects
            if (pThreats[i]->getBulletPtr() != NULL)
            {
                if (pThreats[i]->getBulletPtr()->getIsMove())
                    pThreats[i]->getBulletPtr()->Show(screen);
                pThreats[i]->bulletMove(0, BULLET_SPEED, SCREEN_WIDTH, SCREEN_HEIGHT, RECHARGE_TIME);
            }

            else  //Reset the bullet
            {
                pThreats[i]->setBulletPtr(new Bullet);
                if (pThreats[i]->getBulletPtr() != NULL)
                    pThreats[i]->InitBullet();
            }


            //Check collision between the ship and threat objects or their bullets
            bool is_colMT = SDLCommonFunc::CheckCollision(ship->GetRect(), pThreats[i]->GetRect());  //Ship with threats
            bool is_colMB = SDLCommonFunc::CheckCollision(ship->GetRect(), pThreats[i]->getBulletPtr()->GetRect());  //Ship with threats' bullets

            if (is_colMT || is_colMB)   //If a collision happens, then delete that threats' bullet
            {
                //Remove(Delete) the bullet when it has hit the main object, and then reset it if the threat is still alive
                if (is_colMB)
                {
                    pThreats[i]->resetBullet();
                    ship->updateHP(-THREAT_ATTACK);  //Update HP for the main object                       
                }

                else if (is_colMT)
                    ship->updateHP(-0.1);  //Update HP for the main object

                isDamaged = true;
                pMainHP->setText(std::to_string(ship->getHP()));   //Set new HP to the TextObject                  
            }

            //Check collision between threat objects and ship's bullets
            for (int itb = 0; itb < BulletList.size(); itb++)
            {
                if (itb < BulletList.size())
                {
                    Bullet* bll_ptr = BulletList[itb];
                    if (bll_ptr)
                    {
                        bool is_colTB = SDLCommonFunc::CheckCollision(bll_ptr->GetRect(), pThreats[i]->GetRect());
                        if (is_colTB)  //Collision happens
                        {
                            //Delete that bullet
                            BulletList.erase(BulletList.begin() + itb);  //Remove the bullet when it has hit an threat
                            delete bll_ptr;   //Free up the memory
                            bll_ptr = NULL;

                            //Check HP of that threat
                            if (!pThreats[i]->isAlive(MAIN_ATTACK))
                            {
                                numsDie++;
                                //Update score
                                score += (Round < 3) ? THREAT_HP / 2 : 500;
                                pScore->setText("SCORE " + std::to_string(score));
                                //Get the position of the threat, then apply for explosion later
                                int exPosx = (pThreats[i]->GetRect().x + pThreats[i]->GetRect().w / 2) - EXPLO_WIDTH / 2;
                                int exPosy = (pThreats[i]->GetRect().y + pThreats[i]->GetRect().h / 2) - EXPLO_HEIGHT / 2;
                                explo->SetRect(exPosx, exPosy);
                                isExplo = true;   //Explosion happens, set the flag to true

                                //Delete this hit threat as it dies
                                pThreats.erase(pThreats.begin() + i);
                                NUM_THREATS--;
                                if (NUM_THREATS <= skillMoment && !skillGift_ptr)  //Check when the skill gift happens
                                {
                                    //Make a skill gift (It has the same type with Bullet)
                                    skillGift_ptr = new Bullet;
                                    if (skillGift_ptr)
                                    {
                                        skillGift_ptr->setWidthHeight(SKILL1_SIZE, SKILL1_SIZE);
                                        skillGift_ptr->LoadImg("skill1.png", true, 0);
                                        skillGift_ptr->setIsMove(true);
                                        skillGift_ptr->SetRect(exPosx, exPosy);
                                    }
                                }

                                if (NUM_THREATS <= newBulletMomt && !bulGift_ptr)  //Check when the new bullet gift happens
                                {
                                    //Make a gift (It has the same type with Bullet)
                                    bulGift_ptr = new Bullet;
                                    if (bulGift_ptr)
                                    {
                                        bulGift_ptr->setWidthHeight(57, 60);
                                        bulGift_ptr->LoadImg("newBullet.jpg", false, 0);
                                        bulGift_ptr->setIsMove(true);
                                        bulGift_ptr->SetRect(exPosx, exPosy);
                                    }
                                }

                                //Make the sound
                                Mix_PlayChannel(-1, CHICKEN_SOUND, 0);
                                if ( (Round == 3 && NUM_THREATS > 0) || numsDie % 15 == 0 || (Round < 3 && NUM_THREATS <= 0) )
                                    Mix_PlayChannel(-1, EXPLO_SOUND, 0);
                                
                                break;   //Break the loop, when a threat died.
                            }
                        }
                    }
                }
            }
        }
    }
}



//This function displays the explosion as some threat dies
void Game::makeThreatExplo(Clip* explo, bool& isExplo, int& frameExplo)
{
    if (isExplo)
    {
        explo->setFrame(frameExplo);       
        explo->Show(screen, nullptr, 2);
        frameExplo++;
        if (frameExplo >= THREAT_EXPLO_NUMS * 2)
        {
            frameExplo = 0;
            isExplo = false;
        }
    }
}

//This function displays the explosion as the main object lost
void Game::makeMainExplo(Clip* mExplo, bool& isMExplo, int& frameMExplo)
{
    if (isMExplo)
    {
        if (frameMExplo == 0)
        {
            this->ship->LoadImg("", false, 0);   //Destroy the main object
            Mix_PlayChannel(-1, EXPLO_SOUND, 0);
        }
            
        mExplo->setFrame(frameMExplo);
        mExplo->Show(screen, nullptr, 50);
        frameMExplo++;
        if (frameMExplo >= MAIN_EXPLO_NUMS * 50)
        {
            frameMExplo = 0;
            isMExplo = false;           
        }
    }
}

//This function displays the main object being damaged as hit some threats or their bullets
void Game::damagedShip(bool& isDamaged, int& frameDam)
{
    if (isDamaged || this->ship->getHP() < 25)
    {       
        frameDam++;
        if (frameDam > 90)
        {
            frameDam = 0;
            if(isDamaged)
                Mix_PlayChannel(-1, DAMAGED_SOUND, 0);
            isDamaged = false;
        }

        this->ship->setFrame(frameDam);
        this->ship->Show(screen);
    }
}


//This function displays the skill gift
void Game::skillGift(Bullet* skillGift_ptr, bool& tookSkill)
{
    if (skillGift_ptr)
    {
        if (skillGift_ptr->getIsMove())   //If its is_move = true, display to the screen
        {
            skillGift_ptr->Show(screen);
            skillGift_ptr->HandleMove(0, -1, SCREEN_WIDTH, SCREEN_HEIGHT);

            //Check the collision between the skill gift and the main object
            if (SDLCommonFunc::CheckCollision(skillGift_ptr->GetRect(), ship->GetRect()))
            {
                tookSkill = true;
                //Increase the bullet speed
                BULLET_MAIN_SPEED++;
                //Increase the attack level of the main object's bullets
                MAIN_ATTACK++;
                //Not continue displaying the bullet
                skillGift_ptr->setIsMove(false);
            }
        }
    }
}


//This function displays the new bullet gift
void Game::bulletGift(Bullet* bulGift_ptr, bool& newBullet, bool& tookSkill)
{
    if (bulGift_ptr)
    {
        if (bulGift_ptr->getIsMove())   //If its is_move = true, display to the screen
        {
            bulGift_ptr->Show(screen);
            bulGift_ptr->HandleMove(0, -1, SCREEN_WIDTH, SCREEN_HEIGHT);

            //Check the collision between the new bullet gift and the main object
            if (SDLCommonFunc::CheckCollision(bulGift_ptr->GetRect(), ship->GetRect()))
            {
                newBullet = true;
                if (tookSkill)
                {
                    //Decrease the bullet speed
                    BULLET_MAIN_SPEED--;
                    //Decrease the attack level of the main object's bullets
                    MAIN_ATTACK--;
                    tookSkill = false;
                }
                //Not continue displaying the bullet
                bulGift_ptr->setIsMove(false);
            }
        }
    }
}


//This function checks for the hp gift and displays the hp gift
void Game::hpGift(Bullet* hp_ptr, bool& hpFlag, TextObject* pMainHP, const int& p)
{
    //Check for the HP gift
    if (!hpFlag)
    {
        int hpMoment = rand() % p;
        if (hpMoment < 1)   //The probability of HP gift is (1 / p) every moment
        {
            //Make a gift (It has the same type with Bullet)              
            if (hp_ptr)
            {
                hp_ptr->setIsMove(true);
                hp_ptr->SetRect(rand() % (SCREEN_WIDTH - 70), 0);    //Randomly set the starting position for the hp gift

                hpFlag = true;
            }
        }
    }

    //Display the hp gift
    if (hpFlag)
    {
        if (hp_ptr->getIsMove())   //If its is_move = true, display to the screen
        {
            hp_ptr->Show(screen);
            hp_ptr->HandleMove(0, -1, SCREEN_WIDTH, SCREEN_HEIGHT);

            //Check the collision between the hp gift and the main object
            if (SDLCommonFunc::CheckCollision(hp_ptr->GetRect(), ship->GetRect()))
            {
                //Increase the main object's HP
                ship->updateHP(20);
                pMainHP->setText(std::to_string(ship->getHP()));   //Set new HP to the TextObject
                //Not continue displaying the bullet
                hp_ptr->setIsMove(false);
            }
        }

        else
            hpFlag = false;
    }
}



//This function creates user directions of how to play
int Game::tutorial(SDL_Surface* des)
{
    //An array of file names of the multiple bullets
    const char* file_names[5] = { "double1.png",  "double2.png", "double3.png", "double4.png", "double5.png" };
    //Variables for background movement
    int bg_y = 0;
    int bgCount = 0;
    
    //Load the font
    TTF_Font* font = TTF_OpenFont("times new roman.ttf", 25);
    if (!font)
        return -1;

    TextObject* tutotial = new TextObject(50, 50, "Tutorial 1");
    tutotial->setColor(TextObject::WHITE);
    // Tutorial steps
    const int numItems = 5;    
    TextObject* textTutorial[numItems] = { nullptr };
    textTutorial[0] = new TextObject(50, 100, "Movement Tutorial: Move the ship by mouse motion!");
    textTutorial[0]->setColor(TextObject::WHITE);
    textTutorial[1] = new TextObject(50, 100, "Shoot sphere bullet: click left mouse button!");
    textTutorial[1]->setColor(TextObject::WHITE);
    textTutorial[2] = new TextObject(50, 100, "Take the skill gift whenever you see it!");
    textTutorial[2]->setColor(TextObject::WHITE);
    textTutorial[3] = new TextObject(50, 100, "Take the new bullet gift whenever you see it!");
    textTutorial[3]->setColor(TextObject::WHITE);
    textTutorial[4] = new TextObject(50, 100, "Take the hp gift whenever you see it to increase your hp!");
    textTutorial[4]->setColor(TextObject::WHITE);


    TextObject* ques = new TextObject(50, 150, "Is it fine, move on to the next feature?");
    ques->setColor(TextObject::WHITE);
    TextObject* answerYes = new TextObject(50, 200, "Yes");
    answerYes->setColor(TextObject::WHITE);
    TextObject* answerNo = new TextObject(200, 200, "No, it is failed!");
    answerNo->setColor(TextObject::WHITE);
    TextObject* returnText = new TextObject(50, SCREEN_HEIGHT - 50, "Return main menu");
    answerNo->setColor(TextObject::WHITE);


    //Pointers to the gifts (They have the same type with Bullet)
    Bullet* skillGift_ptr = nullptr;
    Bullet* bulGift_ptr = nullptr;
    Bullet* hp_ptr = new Bullet;
    if (hp_ptr)
    {
        hp_ptr->setWidthHeight(55, 46);
        hp_ptr->LoadImg("heart.png", true, 0);
    }
    bool tookSkill = false;
    bool newBullet = false;
    bool hpFlag = false;
    //Pointer to a TextObject for the main object's HP
    TextObject* pMainHP = new TextObject(17, 11, "100");
    BaseObject* pHeart = new Bullet;
    pHeart->LoadImg("heart.png", true, 0);

    bool flag = false;
    int curTutl = 0;
    //Display test cases through the tutorial via the player's input
    std::cout << std::endl << "****************************** Test Cases ******************************" << std::endl;
    while (true)
    {
        while (SDL_PollEvent(&g_even))
        {
            if (g_even.type == SDL_QUIT)
                return 2;   //The same with Exit option

            else if (g_even.type == SDL_MOUSEMOTION)
            {
                MOUSE_X = g_even.motion.x;
                MOUSE_Y = g_even.motion.y;
                //Check whether a answer option is focused or not
                if (MOUSE_X >= answerYes->GetRect().x && MOUSE_X <= answerYes->GetRect().x + answerYes->GetRect().w
                    && MOUSE_Y >= answerYes->GetRect().y && MOUSE_Y <= answerYes->GetRect().y + answerYes->GetRect().h)
                    answerYes->setColor(TextObject::GREEN);
                else
                    answerYes->setColor(TextObject::WHITE);


                if (MOUSE_X >= answerNo->GetRect().x && MOUSE_X <= answerNo->GetRect().x + answerNo->GetRect().w
                    && MOUSE_Y >= answerNo->GetRect().y && MOUSE_Y <= answerNo->GetRect().y + answerNo->GetRect().h)
                    answerNo->setColor(TextObject::GREEN);
                else
                    answerNo->setColor(TextObject::WHITE);


                if (MOUSE_X >= returnText->GetRect().x && MOUSE_X <= returnText->GetRect().x + returnText->GetRect().w
                    && MOUSE_Y >= returnText->GetRect().y && MOUSE_Y <= returnText->GetRect().y + returnText->GetRect().h)
                    returnText->setColor(TextObject::GREEN);
                else
                    returnText->setColor(TextObject::WHITE);
            }

            //The event of choosing answer 
            else if (g_even.type == SDL_MOUSEBUTTONDOWN)
            {
                MOUSE_X = g_even.motion.x;
                MOUSE_Y = g_even.motion.y;
                //Check whether a option is selected or not
                if (MOUSE_X >= answerYes->GetRect().x && MOUSE_X <= answerYes->GetRect().x + answerYes->GetRect().w
                    && MOUSE_Y >= answerYes->GetRect().y && MOUSE_Y <= answerYes->GetRect().y + answerYes->GetRect().h)
                {
                    //Print out the result of the test case via the player's input
                    std::cout << TestCase[curTutl] + "passed!" << std::endl;

                    if (curTutl == numItems - 1)
                        return 0;    

                    curTutl = (curTutl < numItems - 1) ? (curTutl + 1) : curTutl;
                    tutotial->setText("Tutorial " + std::to_string(curTutl + 1));                  
                }
                    

                if (MOUSE_X >= answerNo->GetRect().x && MOUSE_X <= answerNo->GetRect().x + answerNo->GetRect().w
                    && MOUSE_Y >= answerNo->GetRect().y && MOUSE_Y <= answerNo->GetRect().y + answerNo->GetRect().h)
                {
                    //Print out the result of the test case via the player's input
                    std::cout << TestCase[curTutl] + "failed!" << std::endl;

                    if (curTutl == numItems - 1)
                        return 0;
                   
                    curTutl = (curTutl < numItems - 1) ? (curTutl + 1) : curTutl;
                    tutotial->setText("Tutorial " + std::to_string(curTutl + 1));
                }                    

                if (MOUSE_X >= returnText->GetRect().x && MOUSE_X <= returnText->GetRect().x + returnText->GetRect().w
                    && MOUSE_Y >= returnText->GetRect().y && MOUSE_Y <= returnText->GetRect().y + returnText->GetRect().h)
                    return 0;
            }

            //Shoot sphere bullets by left mouse button
            if (g_even.type == SDL_MOUSEBUTTONDOWN && g_even.button.button == SDL_BUTTON_LEFT && curTutl > 0)
            {
                Bullet* bll_ptr = new Bullet;
                bll_ptr->setWidthHeight(BULLET_WIDTH, BULLET_HEIGHT);
                bll_ptr->LoadImg("Sphere Bullet.png", true, 255);
                bll_ptr->setIsMove(true);
                bll_ptr->SetRect(ship->GetRect().x + ship->GetRect().w / 2 - 10, ship->GetRect().y + 5);
                Mix_PlayChannel(-1, BULLET_SOUND, 0);

                BulletList.push_back(bll_ptr);  //Add a new bullet element into the array            
            }

            //Shoot multiple bullets by right mouse button
            else if (g_even.type == SDL_MOUSEBUTTONDOWN && g_even.button.button == SDL_BUTTON_RIGHT && newBullet)
            {
                for (int i = 0; i < 5; i++)
                {
                    Bullet* bll_ptr = new Bullet((Bullet::BulletDir)(i / 1.5));
                    bll_ptr->setWidthHeight(63, 63);
                    bll_ptr->LoadImg(file_names[i], true, 0);
                    bll_ptr->setIsMove(true);
                    bll_ptr->SetRect(ship->GetRect().x + ship->GetRect().w / 2 + 32 * (i - 3), ship->GetRect().y - 40);
                    BulletList.push_back(bll_ptr);  //Add a new bullet element into the array 
                }

                Mix_PlayChannel(-1, BULLET_SOUND, 0);
            }

            ship->HandleMove(g_even);
        }

        //Apply background
        if (bgCount == 10)   //Used to delay background moving
        {
            bg_y += 1;
            bgCount = 0;
        }
        bgCount++;

        SDLCommonFunc::ApplySurface(bkground, screen, 0, bg_y);
        SDLCommonFunc::ApplySurface(bkground, screen, 0, bg_y - SCREEN_HEIGHT);
        if (bg_y >= SCREEN_HEIGHT)
            bg_y = 0;

        //Show tutorial text
        tutotial->Show(des, font);
        textTutorial[curTutl]->Show(des, font);
        ques->Show(des, font);
        answerYes->Show(des, font);
        answerNo->Show(des, font);
        returnText->Show(des, font);

        //Show the main object out the screen
        ship->Show(des);

        //Make bullet for the main object
        if(curTutl > 0)
            this->makeBullet();

        //Skill gift
        if (curTutl == 2)
        {
            if (!skillGift_ptr || !skillGift_ptr->getIsMove() && !tookSkill)
            {
                skillGift_ptr = new Bullet;
                if (skillGift_ptr)
                {
                    skillGift_ptr->setWidthHeight(SKILL1_SIZE, SKILL1_SIZE);
                    skillGift_ptr->LoadImg("skill1.png", true, 0);
                    skillGift_ptr->setIsMove(true);
                    skillGift_ptr->SetRect(rand() % (SCREEN_WIDTH - SKILL1_SIZE - 10), 0);                   
                }
            }

            this->skillGift(skillGift_ptr, tookSkill);

            if (tookSkill)
                textTutorial[2]->setText("Your bullet speed and attack level were increased!");
        }
        
        //New bullet gift
        if (curTutl == 3)
        {
            if (!bulGift_ptr || !bulGift_ptr->getIsMove() && !newBullet)
            {
                bulGift_ptr = new Bullet;
                if (bulGift_ptr)
                {
                    bulGift_ptr->setWidthHeight(57, 60);
                    bulGift_ptr->LoadImg("newBullet.jpg", false, 0);
                    bulGift_ptr->setIsMove(true);
                    bulGift_ptr->SetRect(rand() % (SCREEN_WIDTH - 70), 0);
                }
            }

            this->bulletGift(bulGift_ptr, newBullet, tookSkill);

            if (newBullet)
                textTutorial[3]->setText("Shoot new bullet by right mouse button! You can still shoot sphere bullet by left one");
        }


        if (curTutl > 3)
        {
            //Show the remaining main object's HP
            pHeart->Show(screen);
            pMainHP->Show(screen, g_font_text);

            //Check for the HP gift and Display the hp gift
            this->hpGift(hp_ptr, hpFlag, pMainHP, 100);         
        }
        
        if (!flag && curTutl == numItems - 1)
        {
            ques->setText("Is it fine, return to the main menu?");           
            flag = true;
        }
            
        //Update the screen     
        SDL_Flip(des);
        
    }


    //Free pointers
    delete font;
    delete tutotial;
    delete skillGift_ptr;
    delete bulGift_ptr;
    delete hp_ptr;
    delete pMainHP;
    delete pHeart;

    return 0;
}




//This function resets necessary static variables for one game (Because we have a loop for game, so it is needed to reset them every loop)
bool Game::reset(bool& displayResult, bool& win)
{
    //Reset for the main object    
    if (displayResult && !win)
    {
        bool ret = ship->LoadImg("Ship3.png", true, 255);
        if (!ret)
            return false;
    }
    this->ship->SetRect(START_XPOS, START_YPOS);
    BULLET_MAIN_SPEED = 1;
    MAIN_ATTACK = 1;
    this->ship->setHP(100);
    this->ship->setFrame(0);

    //Reset for threats
    NUM_THREATS = 30;
    SPEED = 0.2;
    THREAT_HP = 3;
    THREAT_ATTACK = 1;
    BULLET_SPEED = 1;
    RECHARGE_TIME = 1000;

    return true;
}



//This function displays the game result
void Game::result(bool& displayResult, int& Round, bool& win, Clip* mExplo, bool& isMExplo, int& score, TextObject*& resultText,
                  TextObject*& scoreText, TextObject*& returnText, TTF_Font* font1, TTF_Font* font2)
{
    //Check the game result and display if it should
    if (!displayResult && Round == 3 && NUM_THREATS <= 0)   //Win the game
    {
        displayResult = true;
        win = true;
        resultText->setText("YOU WIN");
        resultText->setColor(TextObject::GREEN);
        scoreText->setText("Your score: " + std::to_string(score));
        scoreText->SetRect(SCREEN_WIDTH / 2 - 90, SCREEN_HEIGHT / 2 + 5);
        scoreText->setColor(TextObject::GREEN);
        returnText->setColor(TextObject::GREEN);
    }

    if (!displayResult && this->ship->getHP() <= 0)    //Lost the game
    {
        displayResult = true;
        isMExplo = true;
        resultText->setText("YOU LOST");
        resultText->setColor(TextObject::RED);
        scoreText->setText("Your score: " + std::to_string(score));
        scoreText->SetRect(SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT / 2 + 5);
        scoreText->setColor(TextObject::RED);
        returnText->setColor(TextObject::RED);

        //Get position of the ship for displaying the explosion
        mExplo->SetRect(this->ship->GetRect().x - 25, this->ship->GetRect().y - 100);
    }


    else if (Round == 3 && NUM_THREATS <= 0)
        Mix_PlayChannel(-1, VICTORY_SOUND, 0);   //Play victory sound

    if (displayResult)
    {
        resultText->Show(screen, font1);
        scoreText->Show(screen, font2);
        returnText->Show(screen, font2);
    }
}