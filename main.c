#include <stdio.h>
#include <raylib.h>


int main() {

    //Screen Size
    const int screenwidth = 800;
    const int screenheight = 450;
    float tm = 0.0f;
    bool collided = false;
    int i = 0;
    float cubeSpeed = 0.005f;
    float dem = 1;
    int camCount = 1;
    float score = 0.0f;
    Color strips;
    strips = DARKGRAY;

    SetConfigFlags( FLAG_MSAA_4X_HINT);
    InitWindow(screenwidth,screenheight,"Cube");


    Texture2D background = LoadTexture("../tex/bck.png");

    Vector3 camPos = {15.0f,10.0f,-15.0f};
    Vector3 camTar = {0.0f,0.0f,0.0f};
    Vector3 cubePos= {-4.0f, 0.0f, -30.0f};
    Vector3 cubePos2= {-4.0f, -1.9f, -90.0f};
    Vector3 stripsPos;
    BoundingBox stripsbox;

    float cubeWidth = 2.0f;
    float cubeHeight = 2.0f;
    float cubeLength = 2.0f;

    float cubeWidth1 = 14.1f;
    float cubeHeight1 = 2.0f;
    float cubeLength1 = 2.0f;

    float stripsWidth = 1.9;
    float stripsHeight =1.0;
    float stripsLength = 2.0;


    Camera camera = {0};
    camera.position = camPos;
    camera.target = camTar;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.type = CAMERA_PERSPECTIVE;

    SetCameraMode(camera,CAMERA_PERSPECTIVE);



    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        score += 0.0001;
        tm = (float)GetTime();

        UpdateCamera(&camera);

        camCount++;
        camera.target.z= cubePos.z + 2;
        cubeSpeed += 0.000001f;

        if(camCount>=300)
            camCount = 1;

        if (camCount >=150){
            camera.up.z -= 0.001f;
        }
        else {
            camera.up.z += 0.001f;
        }


        if(IsKeyDown(KEY_W))
            cubeWidth += 0.01f;
        else if(IsKeyDown(KEY_H))
            cubeHeight += 0.01f;
        else if(IsKeyDown(KEY_L))
            cubeLength += 0.01f;

        //Controls
        if(IsKeyDown(KEY_SPACE))
        {
            if(cubePos.y<=4.0f)
                cubePos.y += 0.5f;
        }else
        {
            if(cubePos.y>0.0f)
                cubePos.y -= 0.3f;
        }


        BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawTexture(background,0,0,WHITE);
            BeginMode3D(camera);



                //Player cube
                DrawCube(cubePos, cubeWidth, cubeHeight, cubeLength, BLUE);
                DrawCubeWires(cubePos, cubeWidth, cubeHeight, cubeLength, BLACK);

                BoundingBox playerbox = {(Vector3){cubePos.x-cubeWidth/2,cubePos.y-cubeHeight/2,cubePos.z-cubeLength/2},
                                         (Vector3){cubePos.x+cubeWidth/2,cubePos.y+cubeHeight/2,cubePos.z+cubeLength/2}};


                //DrawBoundingBox(playerbox,RED);


                //side cubes Generator
                for( i = 1; i<=80; i++) {

                    if(i%2==0)
                    {
                        stripsPos = (Vector3){-4.0f, -1.3f, 2.0f * i * -5 + dem};
                        stripsbox = (BoundingBox){(Vector3){stripsPos.x-stripsWidth/2,stripsPos.y-stripsHeight/2,stripsPos.z-stripsLength/2},
                                                 (Vector3){stripsPos.x+stripsWidth/2,stripsPos.y+stripsHeight/2,stripsPos.z+stripsLength/2}};
                        DrawCube(stripsPos,stripsWidth,stripsHeight,stripsLength,strips);
                        DrawBoundingBox(stripsbox,RED);
                        if(CheckCollisionBoxes(playerbox,stripsbox))
                            collided = true;
                    }

                    DrawCube((Vector3) {-10.0f, 0.0f, 2.0f * i * -5 + dem}, 2.0f, 4.0f, 2.0f, GREEN);
                    DrawCube((Vector3) {2.0f, 0.0f, 2.0f * i * -5 + dem}, 2.0f, 4.0f, 2.0f, GREEN);
                    DrawCubeWires((Vector3) {-10.f, 0.0f, 2.0f * i * -5 + dem}, 2.0f, 4.0f, 2.0f, BLACK);
                    DrawCubeWires((Vector3) {2.0f, 0.0f, 2.0f * i * -5 + dem}, 2.0f, 4.0f, 2.0f, BLACK);
                    dem += cubeSpeed;

                }
                if(dem >= 120.0f)
                    dem = 1;


                DrawCube(cubePos2, cubeWidth1, cubeHeight1, cubeLength1+200, BLACK);
                DrawCubeWires(cubePos2, cubeWidth1, cubeHeight1, cubeLength1+200, DARKGRAY);


            EndMode3D();


        //Live Level editing
        if(IsKeyDown(KEY_W))
            DrawText("Width",20,40,20,GREEN);
        else if(IsKeyDown(KEY_H))
            DrawText("Height",20,40,20,GREEN);
        else if(IsKeyDown(KEY_L)){
            DrawText("Length",20,40,20,GREEN);
        }

        if(collided){
            if(tm>10.0f){
                goto  exit;
            }
        }


        DrawFPS(20,20);
        //DrawText((char)score,50,50,30,GREEN);
        EndDrawing();


    }

    exit:CloseWindow();
    return 0;
}
