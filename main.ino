int LED = 3;
int MAX_BRIGHTNESS = 255;
int INCREMENT = 5;

int brightness = 0;
int delta = 5;

void setup()
{
}

void loop()
{
    if (brightness <= 0)
    {
        delta = INCREMENT;
    }
    else if (brightness >= MAX_BRIGHTNESS)
    {
        delta = -INCREMENT;
    }
    brightness += delta;

    analogWrite(LED, brightness);
    delay(30);
}