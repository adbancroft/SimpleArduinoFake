#include <Arduino.h>
#include "SimpleArduinoFake.h"
#include <unity.h>
#include "unity_filename_helper.h"

using namespace fakeit;

static void test_extends_stream(void)
{
    TEST_ASSERT_NOT_EQUAL(
        SimpleArduinoFake::getContext()._Stream.getFake(),
        SimpleArduinoFake::getContext()._Serial.getFake()
    );

    char print_char_var = 'A';
    char stream_char_var = 'B';

    int print_int_var = 123;
    int stream_int_var = 321;

    When(OverloadedMethod(SimpleArduinoFake::getContext()._Stream, print, size_t(char))).AlwaysReturn();
    When(OverloadedMethod(SimpleArduinoFake::getContext()._Stream, print, size_t(int, int))).AlwaysReturn();

    When(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, print, size_t(char))).AlwaysReturn();
    When(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, print, size_t(int, int))).AlwaysReturn();

    Stream* pStream(SimpleArduinoFake::getContext()._Stream.getFake());
    Serial_* serial(SimpleArduinoFake::getContext()._Serial.getFake());

    pStream->print(stream_char_var);
    pStream->print(stream_int_var, DEC);

    serial->print(print_char_var);
    serial->print(print_int_var, DEC);

    Verify(OverloadedMethod(SimpleArduinoFake::getContext()._Stream, print, size_t(char)).Using(stream_char_var)).Once();
    Verify(OverloadedMethod(SimpleArduinoFake::getContext()._Stream, print, size_t(int, int)).Using(stream_int_var, DEC)).Once();

    Verify(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, print, size_t(char)).Using(print_char_var)).Once();
    Verify(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, print, size_t(int, int)).Using(print_int_var, DEC)).Once();
}

static void test_global_serial(void)
{
    When(Method(SimpleArduinoFake::getContext()._Serial, available)).Return(1);
    When(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, print, size_t(char))).Return(1);

    TEST_ASSERT_EQUAL(1, Serial.available());
    TEST_ASSERT_EQUAL(1, Serial.print('A'));

    Verify(Method(SimpleArduinoFake::getContext()._Serial, available)).Once();
    Verify(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, print, size_t(char)).Using('A')).Once();
}

static void test_basics(void)
{
    When(Method(SimpleArduinoFake::getContext()._Serial, end)).AlwaysReturn();
    When(Method(SimpleArduinoFake::getContext()._Serial, flush)).AlwaysReturn();
    When(Method(SimpleArduinoFake::getContext()._Serial, available)).Return(0, 1);
    When(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, write, size_t(uint8_t))).Return(1);
    When(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, begin, void(unsigned long))).AlwaysReturn();

    Serial.begin(9600);

    TEST_ASSERT_EQUAL(0, Serial.available());
    TEST_ASSERT_EQUAL(1, Serial.available());
    TEST_ASSERT_EQUAL(1, Serial.write(5));

    Serial.flush();
    Serial.end();

    Verify(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, begin, void(unsigned long)).Using(9600)).Once();
    Verify(Method(SimpleArduinoFake::getContext()._Serial, available)).Exactly(2_Times);

    Verify(OverloadedMethod(SimpleArduinoFake::getContext()._Serial, write, size_t(uint8_t)).Using(5)).Once();

    Verify(Method(SimpleArduinoFake::getContext()._Serial, flush)).Once();
    Verify(Method(SimpleArduinoFake::getContext()._Serial, end)).Once();
}

namespace SerialTest
{
    void run_tests(void)
    {
        unity_filename_helper_t _ufname_helper(__FILE__);
        RUN_TEST(test_extends_stream);
        RUN_TEST(test_global_serial);
        RUN_TEST(test_basics);
    }
}
