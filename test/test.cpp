#include <random>

#ifdef WIN32

#   include "gtest/gtest.h"

#else
#   include <gtest/gtest.h>
#endif

#include "../var.hpp"

class NumberTest : public ::testing::Test {
protected:
    NumberTest() : r(), e1(r()), int_dist(-10000000, 10000000), double_dist(-10000000.0, 10000000.0) {};

    int getRandomInt() {
        return int_dist(e1);
    }

    double getRandomDouble() {
        return double_dist(e1);
    }

    ~NumberTest() override = default;

private:
    std::random_device r;
    std::default_random_engine e1;

    std::uniform_int_distribution<int> int_dist;
    std::uniform_real_distribution<double> double_dist;
};

TEST_F(NumberTest, additionTest) {
long double n = getRandomInt();
markusjx::var number = std::to_string(n);
EXPECT_EQ(number.operator long double(), n);

number = n;
EXPECT_EQ(number.operator long double(), n);

n++;
number++;
EXPECT_EQ(number.operator long double(), n);

int rnd = getRandomInt();
n +=
rnd;
number +=
rnd;
EXPECT_EQ(number.operator long double(), n);

double r = getRandomDouble();
n +=
r;
number +=
r;
EXPECT_EQ(number.operator long double(), n);
}

TEST_F(NumberTest, subtractionTest) {
long double n = getRandomInt();
markusjx::var number = std::to_string(n);

EXPECT_EQ(number.operator long double(), n);

number = n;
EXPECT_EQ(number.operator long double(), n);

n--;
number--;
EXPECT_EQ(number.operator long double(), n);

int rnd = getRandomInt();
n -=
rnd;
number -=
rnd;
EXPECT_EQ(number.operator long double(), n);

double r = getRandomDouble();
n -=
r;
number -=
r;
EXPECT_EQ(number.operator long double(), n);
}

TEST_F(NumberTest, multiplicationTest) {
long double n = getRandomInt();
markusjx::var number = std::to_string(n);

EXPECT_EQ(number.operator long double(), n);

number = n;
EXPECT_EQ(number.operator long double(), n);

int rnd = getRandomInt();
n *=
rnd;
number *=
rnd;
EXPECT_EQ(number.operator long double(), n);

double r = getRandomDouble();
n *=
r;
number *=
r;
EXPECT_EQ(number.operator long double(), n);
}

TEST_F(NumberTest, divisionTest) {
long double n = getRandomInt();
markusjx::var number = std::to_string(n);

EXPECT_EQ(number.operator long double(), n);

number = n;
EXPECT_EQ(number.operator long double(), n);

int rnd = getRandomInt();
n /=
rnd;
number /=
rnd;
EXPECT_EQ(number.operator long double(), n);

double r = getRandomDouble();
n /=
r;
number /=
r;
EXPECT_EQ(number.operator long double(), n);
}

class StringTest : public ::testing::Test {
protected:
    StringTest() : r(), e1(r()), dist(33, 125), int_dist(-10000000, 10000000) {}

    std::string generateRandomString(unsigned short len) {
        std::string res;
        for (unsigned short i = 0; i < len; i++) {
            res += (char) dist(e1);
        }

        return res;
    }

    int generateRandomInt() {
        return int_dist(e1);
    }

    ~StringTest() override = default;

private:
    std::random_device r;
    std::default_random_engine e1;

    std::uniform_int_distribution<unsigned int> dist;
    std::uniform_int_distribution<int> int_dist;
};

TEST_F(StringTest, test) {
std::string str = generateRandomString(2000);
markusjx::var s = str;
EXPECT_EQ(s.toString(), str);

int i = generateRandomInt();
str.
append(std::to_string(i)
);
s +=
i;

EXPECT_EQ(s.toString(), str);

i = generateRandomInt();
std::string s1 = generateRandomString(200);
int j = generateRandomInt();
std::string s2 = generateRandomString(200);
s.
append(i, s1, j, s2
);
str.
append(std::to_string(i)
).
append(s1)
.
append(std::to_string(j)
).
append(s2);

EXPECT_EQ(s.toString(), str);

s += true;
str.append("true");

EXPECT_EQ(s.toString(), str);
}

TEST(ExcpetionTest, ThrowTest) {
    markusjx::var s = "a";
    EXPECT_ANY_THROW(s());

    EXPECT_ANY_THROW(s[0]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}