

#include "header.h"

#include "AmoObject.h"


int main(int arc, char* argv[])
{


    //Initialize the library SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return 0;
    }

    //Set Window Screen Mode
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL)
    {
        return 0;
    }

   
    //Load Background
    bkground = SDLCommonFunc::LoadImage("bkground.png");
    if (bkground == NULL)
    {
        return 0;
    }




    //Load Human object
    MainObject human_object(HUMAN_OBJECT_WIDTH, HUMAN_OBJECT_HEIGHT);
    human_object.SetRect(300, 420);

    bool ret = human_object.LoadImg("human64x91.png");
    if (!ret)
    {
        return 0;
    }

    else
    {
        //using Color Key to remove background of object 
        UINT32 color_key = SDL_MapRGB(human_object.GetObjectW()->format, 0, 0xFF, 0xFF);
        SDL_SetColorKey(human_object.GetObjectW(), SDL_SRCCOLORKEY, color_key);
    }

    




    //Load Plane object
    MainObject plane_object(PLANE_OBJECT_WIDTH, PLANE_OBJECT_HEIGHT);
    plane_object.SetRect(200, 100);

     ret = plane_object.LoadImg("plane80.png");
    if (!ret)
    {
        return 0;
    }

    else
    {
        //using Color Key to remove background of object 
        UINT32 color_key = SDL_MapRGB(plane_object.GetObjectW()->format, 0, 0xFF, 0xFF);
        SDL_SetColorKey(plane_object.GetObjectW(), SDL_SRCCOLORKEY, color_key);
    }






    bool is_quit = false;
    while (!is_quit)
    {
        while (SDL_PollEvent(&g_even))
        {
            if (g_even.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }

            plane_object.HandleInputAction(g_even);

        }

        plane_object.HandleMove();

        SDLCommonFunc::ApplySurface(bkground, screen, 0, 0);
        human_object.Show(screen);
        plane_object.Show(screen);

        plane_object.makeAmo();
        //for (int i = 0; i < plane_object.getAmoList().size(); ++i)
        //{
        //    std::vector<AmoObject*> amo_list = plane_object.getAmoList();
        //    AmoObject* amo_ptr = amo_list.at(i);

        //    if (amo_ptr != NULL)
        //    {
        //        if (amo_ptr->getIsMove() == true)
        //        {
        //            amo_ptr->HandleMove(10, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        //            amo_ptr->Show(screen);
        //        }

        //        else    //amo_ptr->getIsMove() == false
        //        {
        //            amo_list.erase(amo_list.begin() + i );
        //            plane_object.setAmoList(amo_list);

        //            delete amo_ptr;
        //            amo_ptr = NULL;
        //        }

        //    }
        //}

        if (SDL_Flip(screen) == -1)
        {
            return 0;
        }
    }
    

    SDLCommonFunc::CleanUp(screen, bkground);
    SDL_Quit();


    return 1;
}


