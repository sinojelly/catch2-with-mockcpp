#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"
#include "mockcpp/mockcpp.hpp"

int add(int a, int b) {
    return a + b;
}

SCENARIO( "Two integers add", "[add]" ) {

    GIVEN( "Two integers: 3, 5" ) {
        int a = 3;
        int b = 5;

        WHEN( "Add two integers" ) {
            int c = add(a, b);

            THEN( "The result should be 8" ) {
                REQUIRE( c == 8 );
            }
        }

        WHEN( "Mock add to return 100" ) {
            MOCKER(add).stubs().will(returnValue(100));
            int c = add(a, b);

            THEN( "The result should be 100" ) {
                REQUIRE( c == 100 );
                GlobalMockObject::verify();
            }
        }

        WHEN( "New an object without deletion" ) {
            int* c = new int;

            // catch2 can not report memory leak
            THEN( "The result should be fail of memory leak" ) {
            }
        }
    }
}