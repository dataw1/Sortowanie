#include "pch.h"
#include "gtest/gtest.h"
#include "Kod.cpp" // Dostosuj œcie¿kê do pliku nag³ówkowego
#include <vector>
#include <algorithm> // do std::is_sorted
#include <random>    // do generowania losowych liczb

// Klasa testowa (Test Fixture) - opcjonalna, ale pomaga w organizacji
template <typename T>
class MergeSorterTest : public ::testing::Test {
protected:
    MergeSorter<T> sorter;
};

// 1. Zachowuje tablicê niezmienion¹, gdy ona jest ju¿ posortowana rosn¹co
TEST(MergeSortTest, AlreadySorted) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 2. Potrafi posortowaæ tablicê, która jest posortowana w odwrotnej kolejnoœci
TEST(MergeSortTest, ReverseSorted) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 3. Poprawnie sortuje losow¹ tablicê liczb
TEST(MergeSortTest, RandomArray) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 10, 2, 8, 1, 5 };
    
    sorter.sort(vec);
    
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

// 4. Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortTest, NegativeOnly) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -5, -1, -10, -3 };
    std::vector<int> expected = { -10, -5, -3, -1 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 5. Poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(MergeSortTest, MixedPositiveNegative) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -5, 2, -1, 0, 10, -3 };
    std::vector<int> expected = { -5, -3, -1, 0, 2, 10 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 6. Obs³uguje pust¹ tablicê bez rzucania wyj¹tkiem
TEST(MergeSortTest, EmptyArray) {
    MergeSorter<int> sorter;
    std::vector<int> vec = {};
    
    EXPECT_NO_THROW(sorter.sort(vec));
    EXPECT_TRUE(vec.empty());
}

// 7. Nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortTest, SingleElement) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 42 };
    std::vector<int> expected = { 42 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 8. Poprawnie sortuje tablicê z duplikatami liczb
TEST(MergeSortTest, WithDuplicates) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 3, 1, 2, 3, 1 };
    std::vector<int> expected = { 1, 1, 2, 3, 3 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 9. Poprawnie sortuje tablice ujemn¹ z duplikatami
TEST(MergeSortTest, NegativeWithDuplicates) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -2, -5, -2, -1, -5 };
    std::vector<int> expected = { -5, -5, -2, -2, -1 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 10. Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, MixedWithDuplicates) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { -2, 5, 0, -2, 5, 1 };
    std::vector<int> expected = { -2, -2, 0, 1, 5, 5 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 11. Poprawnie sortuje tablicê zawieraj¹c¹ tylko dwa elementy w kolejnoœci rosn¹cej
TEST(MergeSortTest, TwoElementsSorted) {
    MergeSorter<int> sorter;
    std::vector<int> vec = { 1, 10 };
    std::vector<int> expected = { 1, 10 };
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec, expected);
}

// 12. Poprawnie sortuje du¿¹ tablicê zawieraj¹c¹ ponad 100 elementów
TEST(MergeSortTest, LargeArray) {
    MergeSorter<int> sorter;
    std::vector<int> vec;
    // Generowanie 150 liczb
    for (int i = 150; i > 0; --i) {
        vec.push_back(i);
    }
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec.size(), 150);
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

// 13. Poprawnie sortuje du¿¹ tablicê (>100 el.) z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, LargeMixedArrayWithDuplicates) {
    MergeSorter<int> sorter;
    std::vector<int> vec;
    
    // U¿ywamy generatora losowego dla lepszego testu
    std::mt19937 rng(42); // sta³e ziarno dla powtarzalnoœci
    std::uniform_int_distribution<int> dist(-50, 50);

    for (int i = 0; i < 200; ++i) {
        vec.push_back(dist(rng));
    }
    
    sorter.sort(vec);
    
    EXPECT_EQ(vec.size(), 200);
    EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}