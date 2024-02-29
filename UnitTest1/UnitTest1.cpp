#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3(1)/lab7.3(1).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreate)
        {
            int n = 2;
            int Low = 1, High = 2;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];
            Create(a, n, Low, High);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }
            for (int i = 0; i < n; i++) delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestPrint)
        {
            int n = 2;
            int Low = 1, High = 2;
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];

            Create(testMatrix, n, Low, High);
            stringstream buffer;
            streambuf* prevCoutBuf = cout.rdbuf(buffer.rdbuf());
            Print(testMatrix, n);
            cout.rdbuf(prevCoutBuf);
            for (int i = 0; i < n; i++) delete[] testMatrix[i];
            delete[] testMatrix;
        }

        TEST_METHOD(TestRotate90Degrees)
        {
            int n = 4; 
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    testMatrix[i][j] = i * n + j;
                }
            }
            int numberOfRepetitions = 1;
            Rotate90Degrees(testMatrix, n, numberOfRepetitions);
            bool isCorrectlyRotated = true;
            for (int i = 0; i < n; i++) {
                if (testMatrix[i][n - 1] != i) {
                    isCorrectlyRotated = false;
                    break;
                }
            }
            Assert::IsTrue(isCorrectlyRotated);
            for (int i = 0; i < n; i++) delete[] testMatrix[i];
            delete[] testMatrix;
        }

        TEST_METHOD(TestColumnWithMostZeros)
        {
            int n = 3; 
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];
            testMatrix[0][0] = 1; testMatrix[0][1] = 0; testMatrix[0][2] = 1;
            testMatrix[1][0] = 1; testMatrix[1][1] = 0; testMatrix[1][2] = 1;
            testMatrix[2][0] = 1; testMatrix[2][1] = 1; testMatrix[2][2] = 1;
            int columnIndex = ColumnWithMostZeros(testMatrix, n);
            Assert::AreEqual(1, columnIndex);
            for (int i = 0; i < n; i++) delete[] testMatrix[i];
            delete[] testMatrix;
        }
	};
}