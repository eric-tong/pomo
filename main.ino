int LED_PIN = 3;
int BUTTON_PIN = 12;

int MAX_BRIGHTNESS = 255;
int INCREMENT = 5;

int brightness = 0;
int delta = 5;

void setup()
{
    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
    if (digitalRead(BUTTON_PIN) == HIGH)
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
    }
    else
    {
        brightness = 0;
    }
    analogWrite(LED_PIN, brightness);
    delay(30);
}