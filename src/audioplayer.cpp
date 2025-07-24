#include "audioplayer.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Audio/Sound.hpp"

void audioplayer::play_ruqia()
{
    Audio::Sound ruqia { "Audio/ruqia.wav" };
    ruqia.play();
}

void audioplayer::play_morning_athkar()
{

}
