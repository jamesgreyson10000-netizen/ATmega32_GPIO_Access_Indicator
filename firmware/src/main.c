#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/* ── Pin aliases ─────────────────────────────── */
#define BTN_OK      PA0   /* Correct access button */
#define BTN_WRONG   PA1   /* Wrong access button   */
#define BTN_RESET   PA2   /* Reset button          */

#define LED_GREEN   PB0
#define LED_RED     PB1
#define LED_YELLOW  PB2
#define BUZZER      PB3

/* ── Helper macros ───────────────────────────── */
#define BTN_PRESSED(pin)   ( !(PINA & (1 << (pin))) )
#define BTN_RELEASED(pin)  (   PINA & (1 << (pin))  )

int main(void)
{
    /* PORTA = all inputs */
    DDRA  = 0x00;
    /* Enable internal pull-ups on PA0..PA2 */
    PORTA = 0xFF;

    /* PB0..PB3 = outputs */
    DDRB  = (1<<LED_GREEN) | (1<<LED_RED) | (1<<LED_YELLOW) | (1<<BUZZER);
    PORTB = 0x00;   /* all OFF */

while (1)
{
    /* Standby */
    PORTB = (1 << LED_YELLOW);

    /* Correct Access */
    if (BTN_PRESSED(BTN_OK))
    {
        PORTB = 0;

        /* Single blink and beep */
        PORTB |= (1 << LED_GREEN);
        PORTB |= (1 << BUZZER);

        _delay_ms(200);

        PORTB &= ~(1 << BUZZER);

        /* Stay active for remaining time */
        for(uint16_t i = 0; i < 3800; i += 100)
        {
            if(BTN_PRESSED(BTN_RESET))
                break;

            _delay_ms(100);
        }

        PORTB = 0;

        while(BTN_PRESSED(BTN_OK));
        _delay_ms(50);
    }

    /* Wrong Access */
    else if (BTN_PRESSED(BTN_WRONG))
    {
        PORTB = 0;

        PORTB |= (1 << LED_RED);

        /* First beep */
        PORTB |= (1 << BUZZER);
        _delay_ms(200);
        PORTB &= ~(1 << BUZZER);

        _delay_ms(200);

        /* Second beep */
        PORTB |= (1 << BUZZER);
        _delay_ms(200);
        PORTB &= ~(1 << BUZZER);

        /* Remain active for 10 seconds */
        for(uint16_t i = 0; i < 9400; i += 100)
        {
            if(BTN_PRESSED(BTN_RESET))
                break;

            _delay_ms(100);
        }

        PORTB = 0;

        while(BTN_PRESSED(BTN_WRONG));
        _delay_ms(50);
    }

    /* Reset */
    else if (BTN_PRESSED(BTN_RESET))
    {
        PORTB = 0;

        PORTB |= (1 << LED_YELLOW);

        while(BTN_PRESSED(BTN_RESET));
        _delay_ms(50);
    }
}
    return 0;
}