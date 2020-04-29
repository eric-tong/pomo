int BUTTON_PIN = 0;
int LED_PIN = 3;

int MAX_BRIGHTNESS = 255;
int INCREMENT = 5;

int brightness = 0;
int delta = 5;

bool pressState = false;
bool isActive = true;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    bool isPressed = analogRead(BUTTON_PIN) < 800;
    if (pressState && !isPressed)
    {
        Serial.println("Toggle State");
        isActive = !isActive;
    }
    pressState = isPressed;

    if (isActive)
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