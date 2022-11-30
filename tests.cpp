// tests.cpp
// Program 5: mymap
// Course: CS 251, Fall 2022. Thursday 12pm lab
//
// Author: Alex Bernatowicz
//
// The tests.cpp file is a file where I created my google tests and mostly unit tests.
// The file consists of tests for every member function of the mymap.h class a handful
// of the tests were seeded with a range very high such as 1000, 100,000, or 1,000,000
// and put random numbers including duplicates to stress test functions.
//
// #include <gtest/gtest.h>
#include "mymap.h"
#include <iostream>
#include "myrandom.h"
#include <map>
using namespace std;

// gtest stopped working on 11/12/22 in the morning had to continue testing with unit tests, unit test start on line 117

// TEST(mymap, putFunctionForSize) {
//     mymap<int, int> map;
//     int arr[] = {2, 1, 3};
    
//     for(int i = 0; i < 3; i++) {
//         map.put(arr[i], arr[i]);
//     }
    
//     ASSERT_EQ(map.Size(), 3);
// }

// TEST(mymap, putFunctionForSize2) {
//     mymap<int, float> map1;
//     float arr[] = {10.5, 9.5, 8.5, 7.5, 6.5, 5.5};

//     for(int i = 0; i < 6; i++) {
//         map1.put(arr[i], arr[i]);
//     }

//     ASSERT_EQ(map1.Size(), 6);
// }

// TEST(mymap, containFunction) {
//     mymap<int, int> map1;
//     mymap<int, string> map2;

//     int arr[] = {2, 1, 3};
//     string arr2[] = {"Alex", "John", "Pedro", "Iza", "Daniel"};

//     for(int i = 0; i < 3; i++) {
//         map1.put(arr[i], arr[i]);
//     }

//     for(int i = 0; i < 5; i++) {
//         map2.put(arr[i], arr2[i]);
//     }

//     for(int i = 0; i < 3; i++) {
//         EXPECT_TRUE(map1.contains(arr[i]));
//     }

//     for(int i = 0; i < 5; i++) {
//         EXPECT_TRUE(map2.contains(arr[i]));
//     }
// }

// TEST(mymap, getFunction) {
//     mymap<int, int> map1;

//     int arr[] = {2, 1, 3};

//     for(int i = 0; i < 3; i++) {
//         map1.put(arr[i], arr[i]);
//     }

//     for(int i = 0; i < 3; i++) {
//         ASSERT_EQ(map1.get(arr[i]), arr[i]);
//         ASSERT_EQ(map1.Size(), 3);
//     }
// }

// TEST(mymap, toStringFunction) {
//     mymap<int, int> map1;

//     int arr[] = {2, 4, 6, 1};

//     for (int i = 0; i < 4; i++) {
//         map1.put(i, arr[i]);
//     }

//    cout << map1.toString();

//    string sol = "key: 1 value: 1\nkey:2 value: 2\nkey: 3 value: 3\n";

//     EXPECT_EQ(sol, map1.toString());
    
// }

// TEST(mymap, bracketOperator) {
//     mymap<int, int> map1;

//     int arr[] = {2, 1, 3, 5 };

//     for(int i = 0; i < 4; i++) {
//         map1.put(arr[i], arr[i]);
//     }

//     for(int i = 0; i < 4 ; i++) {
//         EXPECT_EQ(map1[arr[i]], arr[i]);
//         EXPECT_EQ(map1.Size(), 4);
//     }

//     cout << map1.toString();
// }

// ----------------------------------------------------------------
// begin Unit Tests

// begin tests for size
void testPutForSize() {
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
        
    for(int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }

    if(map.Size() != 3) {
        cout << "Size Test 1 Failed!" << endl;
    }
    else {
        cout << "Size Test 1 Passed!" << endl;
    }
}

void testPutForSize2() {
    mymap< int, string> map1;
    int array[] = {5, 7, 3, 2, 10};
    string arr[] = {"Alex", "John", "Monica", "Iza", "Pedro"};

    for(int i = 0; i < 5; i++) {
        map1.put(array[i], arr[i]);
    }

    if(map1.Size() != 5) {
        cout << "Size Test 2 Failed!" << endl;
    }
    else {
        cout << "Size Test 2 Passed!" << endl;
    }

}

void testPutForSize3() {
    mymap< int, string> map1;
    int array[] = {5, 7, 5, 2, 10};
    string arr[] = {"Alex", "John", "Monica", "Iza", "Pedro"};

    for(int i = 0; i < 5; i++) {
        map1.put(array[i], arr[i]);
    }

    if(map1.Size() != 4) {
        cout << "Size Test 3 Failed!" << endl;
    }
    else {
        cout << "Size Test 3 Passed!" << endl;
    }
}

void testPutForSize4() {
    mymap<int, float> map1;
    float arr[] = {10.5, 9.5, 8.5, 7.5, 6.5, 5.5, 4.5};

    for(int i = 0; i < 7; i++) {
        map1.put(i, arr[i]);
    }

    if(map1.Size() != 7) {
        cout << "Size Test 4 Failed!" << endl;
    }
    else {
        cout << "Size Test 4 Passed!" << endl;
    }
    cout << "more tests will print, next test is comparing sizes of maps with very large stress test seed" << endl;
}

void testPutForSizeStressTest() {
    mymap<int, int> map1;
    map<int, int> map2;
    int seed = 10000000;

    for(int i = 0; i < seed; i++) {
        int key = randomInteger(0, seed);
        int value = randomInteger(0, seed);
        map1.put(key, value);
        map2.insert({key, value});
    }

    if(map1.Size() != map2.size()) {
        cout << "Test Put For Size Stress Test Failed!" << endl;
    }
    else {
        cout << "Test Put For Size Stress Test Passed!" << endl;
    }
}
// end tests for size
// ----------------------------------------------------------------
// begin tests to string
void testToString1() {
    mymap<int, int> map;
    int arr[] = {2, 1, 3};
        
    for(int i = 0; i < 3; i++) {
        map.put(arr[i], arr[i]);
    }

    cout << map.toString() << endl;
}

void testToString2() {
    mymap< int, string> map1;
    string arr[] = {"Alex", "John", "Monica", "Iza", "Pedro"};

    for(int i = 0; i < 5; i++) {
        map1.put(i, arr[i]);
    }

    cout << map1.toString() << endl;
}

void testToString3() {
    mymap<int, float> map1;
    float arr[] = {10.5, 9.5, 8.5, 7.5, 6.5, 5.5, 4.5};

    for(int i = 0; i < 7; i++) {
        map1.put(i, arr[i]);
    }

    cout << map1.toString() << endl;
}

void testToString4() {
    mymap< int, string> map1;
    int array[] = {5, 7, 5, 2, 10};
    string arr[] = {"Alex", "John", "Monica", "Iza", "Pedro"};

    for(int i = 0; i < 5; i++) {
        map1.put(array[i], arr[i]);
    }

    cout << map1.toString() << endl;
}
// end tests for to string
// ----------------------------------------------------------------
// begin tests size and to string
void testPutForSizeAndToString() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    cout << map1.toString() << endl;
}

void testPutForSizeAndToString2() {
    mymap<float, float> map1;
    float arr1[] = {3.2, 5.6, 4.5, 2.2, 2.8, 9.9, 3.2};
    float arr2[] = {97.6, 68.5, 70.2, 45.7, 80.3, 32.8, 125.7};

    for(int i = 0; i < 7; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    if(map1.Size() != 6) {
        cout << "testPutForSizeAndToString2 size is incorrect!" << endl;
    }
    else {
        cout << "testPutForSizeAndToString2 size is correct" << endl;
    }

    cout << map1.toString() << endl;
}

void testPutForSizeAndToString3() {
    mymap<int, int> map1;
    int arr1[] = {5, 6, 8, 7, 9};
    int arr2[] = {45, 63, 27, 33, 55};

    for(int i = 0; i < 5; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    if(map1.Size() != 5) {
        cout << "testPutForSizeAndToString3 size is wrong!" << endl;
    }
    else {
        cout << "testPutForSizeAndToString3 size is correct!" << endl;
    }

    cout << map1.toString() << endl;
}

void testPutForSizeAndToString4() {
    mymap<int, int> map1;
    int arr1[] = {9, 7, 8, 6, 5};
    int arr2[] = {45, 63, 27, 33, 55};

    for(int i = 0; i < 5; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    if(map1.Size() != 5) {
        cout << "testPutForSizeAndToString3 size is wrong!" << endl;
    }
    else {
        cout << "testPutForSizeAndToString3 size is correct!" << endl;
    }

    cout << map1.toString() << endl;
}
// end tests for size and to string
// ----------------------------------------------------------------
// begin tests for size and to string stress test
void testPutForSizeAndToStringStressTest() {
    mymap<int, int> map1;
    int seed = 100;

    for(int i = 0; i < seed; i++) {
        int key = randomInteger(0, seed);
        int value = randomInteger(0, seed);
        map1.put(key, value);
    }

    cout << map1.Size() << endl;
    cout << map1.toString() << endl;
}

// end tests for size and to string stress test
// ----------------------------------------------------------------
// beign tests for size after threading
void testPutForSizeAfterThreading() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }
    cout << map1.Size() << endl;
}
// end tests for size after threading
// ----------------------------------------------------------------
// begin tests for contain function
void testContainFunction() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    if(map1.contains(10) == 1) {
        cout << "First Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(2) == 1) {
        cout << "Second Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(200) == 1) {
        cout << "Thrid Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(6) == 1) {
        cout << "Fourth Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(5) == 1) {
        cout << "Fifth Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(65) == 0) {
        cout << "Sixth Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(105) == 0) {
        cout << "Seventh Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(8) == 0) {
        cout << "Eighth Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(3) == 1) {
        cout << "Ninth Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.contains(7) == 1) {
        cout << "Tenth Contain Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    cout << endl;
}
// end tests for contain function
// ----------------------------------------------------------------
// begin tests for get function
void testGetFunction(){
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    if(map1.get(10) == 3) {
        cout << "First Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(2) == 6) {
        cout << "Second Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(200) == 32) {
        cout << "Thrid Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(6) == 1) {
        cout << "Fourth Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(5) == 2) {
        cout << "Fifth Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(65) == 0) {
        cout << "Sixth Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(105) == 0) {
        cout << "Seventh Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(8) == 0) {
        cout << "Eighth Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(3) == 65) {
        cout << "Ninth Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    if(map1.get(7) == 74) {
        cout << "Tenth Get Assert Passed" << endl;
    }
    else {
        cout << "Assert Failed" << endl;
    }
    cout << endl;
}
// end tests for get function
// ----------------------------------------------------------------
// begin tests for bracket operator
void testBracketOperator() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    if(map1[2] != 6) {
        cout << "Bracket Operator Assert 1 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 1 Passed!" << endl;
    }
    if(map1[9] != 9) {
        cout << "Bracket Operator Assert 2 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 2 Passed!" << endl;
    }
    if(map1[3] != 65) {
        cout << "Bracket Operator Assert 3 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 3 Passed!" << endl;
    }
    if(map1[4] != 54) {
        cout << "Bracket Operator Assert 4 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 4 Passed!" << endl;
    }
    if(map1[8] != 0 && map1.Size() != 11) {
        cout << "Bracket Operator Assert 5 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 5 Passed!" << endl;
    }
    if(map1[75] != 0 && map1.Size() != 12) {
        cout << "Bracket Operator Assert 6 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 6 Passed!" << endl;
    }
    if(map1[87] != 0 && map1.Size() != 13) {
        cout << "Bracket Operator Assert 7 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 7 Passed!" << endl;
    }
    if(map1[62] != 0 && map1.Size() != 14) {
        cout << "Bracket Operator Assert 8 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 8 Passed!" << endl;
    }
    if(map1[8] != 0) {
        cout << "Bracket Operator Assert 9 Failed!" << endl;
    }
    else {
        cout << "Bracket Operator Assert 9 Passed!" << endl;
    }
}
// end tests for bracket operator
// ----------------------------------------------------------------
// begin tests for iterator
void testIterator() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 7, 13};
    int arr2[] = {1, 3, 5, 6, 2, 7};

    for(int i = 0; i < 6; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    for (auto key : map1) {
        cout << key << endl;
    }
    cout << endl;
}

void testIterator2() {
    mymap<float, string> map1;

    float arr1[] = {4.35, 2.46, 5.45, 6.69, 4.20, 1.63, 2.46};
    string arr2[] = {"Alex", "John", "Iza", "Martin", "Pedro", "Daniel", "Basim"};

    for(int i = 0; i < 7; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    for (auto key : map1) {
        cout << key << endl;
    }
    
    cout << map1.toString();
}

void testIterator3() {
    mymap<string, string> map1;
    string arr1[] = {"Alex", "John", "Daniel", "Martin"};
    string arr2[] = {"Iza", "Shannon", "Madzia", "Heavy"};

    for(int i = 0; i < 4; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    for (auto key : map1) {
        cout << key << endl;
    }
    
    cout << map1.toString();


}
// end tests for iterator
// ----------------------------------------------------------------
// begin tests for clear function
void testClearFunction1() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    map1.clear();

    if(map1.Size() != 0) {
        cout << "Clear Failed!" << endl;
    }
    else {
        cout << "Clear Passed!" << endl;
    }
    cout << map1.Size() << endl;
}

void testClearFunction2() {
    mymap<int, int> map1;

    int arr1[] = {5, 6, 7, 9, 8, 10, 12};
    int arr2[] = {90, 100, 110, 120, 130, 140, 150};

    for(int i = 0; i < 7; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    map1.clear();

    if(map1.Size() != 0) {
        cout << "Clear Failed!" << endl;
    }
    else {
        cout << "Clear Passed!" << endl;
    }
    cout << map1.Size() << endl;
}

void testClearFunction3() {
    mymap<int, int> map1;

    int arr1[] = {5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17};
    int arr2[] = {90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    map1.clear();

    if(map1.Size() != 0) {
        cout << "Clear Failed!" << endl;
    }
    else {
        cout << "Clear Passed!" << endl;
    }
    cout << map1.Size() << endl;
}

void testClearFunction4() {
    mymap<int, int> map1;

    int arr1[] = {8, 7, 6, 5, 4};
    int arr2[] = {10, 15, 20, 25, 30};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    map1.clear();

    if(map1.Size() != 0) {
        cout << "Clear Failed!" << endl;
    }
    else {
        cout << "Clear Passed!" << endl;
    }
    cout << map1.Size() << endl;       
}

void testClearFunctionStressTest() {
    mymap<int, int> map1;

    int seed = 100000;

    for(int i = 0; i < seed; i++) {
        int key = randomInteger(0, seed);
        int value = randomInteger(0,seed);
        map1.put(key, value);
    }
    cout << endl;
    cout << "Map Size Before Clear" << endl;
    cout << map1.Size() << endl << "Calling Clear Now: " << endl;
    map1.clear();
    cout << map1.Size() << endl;
}
// end tests for clear function
// ----------------------------------------------------------------
// begin tests for equal operator
void testEqualOperator() {
    mymap<int, int> map1;
    mymap<int, int> map2;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    map2 = map1;

    cout << map2.Size() << endl;
    cout << map1.toString() << endl << endl;
    cout << map2.toString() << endl;
}

void testEqualOperator2() {
    mymap<int, int> map1;
    mymap<int, int> map2;
    int arr1[] = {11, 12, 13, 14, 15, 16};
    int arr2[] = {21, 22, 23, 24, 25, 26};

    for(int i = 0; i < 6; i++) {
        map1.put(arr1[i], arr2[i]);
    }

    map2 = map1;

    cout << map2.Size() << endl;
    cout << map1.toString() << endl << endl;
    cout << map2.toString() << endl;
}

void testEqualOperatorStressTest() {
    mymap<int, int> map1;
    mymap<int, int> map2;

    int seed = 1000000;

    for(int i = 0; i < seed; i++) {
        int key = randomInteger(0, seed);
        int value = randomInteger(0, seed);
        map1.put(key, value);
    }

    map2 = map1;

    cout << "Map 1 Size: " << map1.Size() << endl;
    cout << "Map 2 Size: " << map2.Size() << endl;
}
// end tests for equal operator
// ----------------------------------------------------------------
// begin tests for copy constructor
void testCopyConstructor() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }
    mymap<int, int> mapCopy = map1;

    cout << "Map 1 size is " << map1.Size() << endl;
    cout << "Copied map size is " << mapCopy.Size() << endl;

    cout << "Map 1 is:" << endl;
    cout << map1.toString() << endl;

    cout << "Copied map is:" << endl;
    cout << mapCopy.toString() << endl << endl;
}

void testCopyContstructorStressTest() {
    mymap<int, int> map1;

    int seed = 1000000;

    for(int i = 0; i < seed; i++) {
        int key = randomInteger(0, seed);
        int value = randomInteger(0, seed);
        map1.put(key, value);
    }

    mymap<int, int> mapCopy = map1;

    // cout << "Map 1 is:" << endl;
    // cout << map1.toString() << endl;

    // cout << "Copied map is:" << endl;
    // cout << mapCopy.toString() << endl << endl;

    cout << "Map 1 size is " << map1.Size() << endl;
    cout << "Copied map size is " << mapCopy.Size() << endl;

}
// end tests for copy constructors
// ----------------------------------------------------------------
// begin tests for copy constructor and clear
void testCopyConstructorAndClear() {
    mymap<int, int> map1;
    int arr1[] = {5, 10, 3, 2, 5, 6, 1, 4, 9, 200, 3, 7};
    int arr2[] = {1, 3, 5, 6, 2, 1, 435, 54, 9, 32, 65, 74};

    for(int i = 0; i < 12; i++) {
        map1.put(arr1[i], arr2[i]);
    }
    map1.clear();
    mymap<int, int> mapCopy = map1;

    cout << "Map 1 size is " << map1.Size() << endl;
    cout << "Copied map size is " << mapCopy.Size() << endl;

    cout << "Map 1 is:" << endl;
    cout << map1.toString() << endl;

    cout << "Copied map is:" << endl;
    cout << mapCopy.toString() << endl << endl;
}
// end tests for copy constructor and clear
// ----------------------------------------------------------------
// begin tests for to vector function
// mmich3@uic.edu
// 655103220
bool testToVector(){
    mymap<int,int> map1;
    stringstream output;
    for(int i = 0; i < 5; i++) {
        map1.put(i,i);
    }

    vector<pair<int,int>> vector;
    vector = map1.toVector();

    for(int i = 0; i < vector.size(); i++) {
        output << vector[i].first << endl;
    }

    if(output.str() != "0\n1\n2\n3\n4\n") {
        cout << "myMapToVecorTest: Test 1: 5 int nodes failed" << endl;
        return false;
    }

    cout << "myMapToVectorTests: all passed!" << endl;
    return true;
}
// end tests for to vector
// ----------------------------------------------------------------
// begin tests for check balance
// mmich3@uic.edu
// 655103220
bool testCheckBalance() {
    mymap<int,int> map1;
    map1.put(5,5); map1.put(8,8); map1.put(11,11);
    string answer1 = "key: 5, nL: 0, nR: 2\nkey: 8, nL: 0, nR: 1\nkey: 11, nL: 0, nR: 0\n";

    if(answer1 != map1.checkBalance()) {
        cout << "myMapCheckBalanceTest: Test 1: 3 nodes failed" << endl;
        return false;
    }

    map1.put(3,3);
    answer1 = "key: 5, nL: 1, nR: 2\nkey: 3, nL: 0, nR: 0\nkey: 8, nL: 0, nR: 1\nkey: 11, nL: 0, nR: 0\n";

    if(answer1 != map1.checkBalance()) {
        cout << "myMapCheckBalanceTest: Test 2: add a left node failed" << endl;
        return false;
    }
    cout << "All tests passed!" << endl;
    return true;
}
// end tests for check balance
// ----------------------------------------------------------------
int main(){
    // test put for size
    testPutForSize();
    testPutForSize2();
    testPutForSize3();
    testPutForSize4();
    testPutForSizeStressTest();
    // test to string function
    testToString1();
    testToString2();
    testToString3();
    testToString4();
    // test size and to string functions together
    testPutForSizeAndToString();
    testPutForSizeAndToString2();
    testPutForSizeAndToString3();
    testPutForSizeAndToString4();
    testPutForSizeAndToStringStressTest();
    // test put for size after thread was completed
    testPutForSizeAfterThreading();
    // test contain function
    testContainFunction();
    // test get function
    testGetFunction();
    // test bracket operator
    testBracketOperator();
    // test iterator
    testIterator();
    testIterator2();
    testIterator3();
    // test clear function call
    testClearFunction1();
    testClearFunction2();
    testClearFunction3();
    testClearFunction4();
    testClearFunctionStressTest();
    // test equal operator call
    testEqualOperator();
    testEqualOperator2();
    testEqualOperatorStressTest();
    // test copy constructor
    testCopyConstructor();
    testCopyContstructorStressTest();
    // test copy constructor and clear together
    testCopyConstructorAndClear();
    // test to vector
    testToVector();
    // test check balance
    testCheckBalance();

}