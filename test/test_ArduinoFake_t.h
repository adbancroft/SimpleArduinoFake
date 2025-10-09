#ifdef UNIT_TEST

namespace ArduinoFakeTTest
{
    struct IDummy
    {
        virtual long dummyMethod(void) = 0;
    };

    void test_reset(void)
    {
        ArduinoFake_t<IDummy> arduinoFake;

        auto method = Method(arduinoFake.Fake, dummyMethod);
        When(method).AlwaysReturn(101L);
        
        Verify(method).Never();

        // Call the "real" method...
        arduinoFake.getFake()->dummyMethod();
        // ...which should call the faked method
        Verify(method).Once();

        // Reset
        arduinoFake.Reset();
        
        try {
            // This should throw an exception...
            arduinoFake.getFake()->dummyMethod();
            // ...fail the test if not.
            TEST_FAIL();
        }
        catch (fakeit::FakeitException &e) {
            Verify(method).Never();
        }
    }

    void run_tests(void)
    {
        RUN_TEST(ArduinoFakeTTest::test_reset);
    }
}

#endif