#include "stdafx.h"
#include "credit-card-validator2.cpp"
#include "assert.h"

namespace UnitTest {
    [TestClass]
    public ref class UnitTest
    {
        public: 
        [TestMethod]
        void Test_digits_only() {
            input = "ABC"
            auto actual = digits_only(input);
            auto expected = false; 
            Assert::AreEqual(expected, actual);
        }

        [TestMethod] 
        void Test_digits_only2() {
            input = "123";
            auto actual = digits_only(input); 
            auto expected = true; 
            Assert::AreEqual(expected, actual);
        }

        [TestMethod] 
        void Test_digits_only_mixture() {
            input = "123ABC";
            auto actual = digits_only(input); 
            auto expected = false; 
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_doublerightleft() {
            string = "123456";
            auto actual = double_right_left(string);
            auto expected = {2, 2, 6, 4, 1, 6};
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_doublerightleft2() {
            string = "23480956";
            auto actual = double_right_left(string);
            auto expected = {6, 1, 9, 0, 8, 8, 3, 4};
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_sumAll() {
            input = {6, 1, 9, 0, 8, 8, 3, 4};
            auto actual = sum_all(input); 
            auto expected = 39;
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_sumAll2() {
            input = {2, 2, 6, 4, 1, 6};
            auto actual = sum_all(input);
            auto expected = 21; 
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_identify_bank_AmEx() {
            input = "345678";
            auto actual = identify_bank(input); 
            expected = "American Express";
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_identify_bank_Visa() {
            input = "456789";
            auto actual = identify_bank(input);
            auto expected = "Visa";
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_identify_bank_unknown() {
            input = "123456";
            auto actual = identify_bank(input); 
            auto expected = "Unknown bank";
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_identify_bank_Master() {
            input = "567891";
            auto actual = identify_bank(input);
            auto expected = "MasterCard";
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_identify_bank_Discover() {
            input = "678901";
            auto actual = identify_bank(input); 
            auto expected = "Discover";
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_identify_industry_Airline() {
            input = "123456";
            input2 = "234567"; 
            auto actual = identify_industry(input); 
            auto expected = "Airline"; 
            auto actual2 = identify_industry(input2);
            auto expected2 = "Airline";
            Assert::AreEqual(expected, actual); 
            Assert::AreEqual(expected2, actual2); 
        }

        [TestMethod] 
        void Test_identify_industry_Travel() {
            input = "345678";
            auto actual = identify_industry(input); 
            auto expected = "travel";
            Assert::AreEqual(expected, actual); 
        }

        [TestMethod] 
        void Test_identify_industry_Bank() {
            input = "456789";
            input2 = "567890";
            input3 = "678901"; 
            auto actual = identify_industry(input); 
            auto actual2 = identify_industry(input2);
            auto actual3 = identify_industry(input3); 
            auto expected = "Bank";
            auto expected2 = "Bank"; 
            auto expected3 = "Bank"; 
            Assert::AreEqual(expected, actual);
            Assert::AreEqual(expected2, actual2);
            Assert::AreEqual(expected3, actual3);
        }

        [TestMethod] 
        void Test_identify_industry_Gas() {
            input = "789012";
            auto actual = identify_industry(input); 
            auto expected = "Gas";
            Assert::AreEqual(expected, actual); 
        }
    }
}
