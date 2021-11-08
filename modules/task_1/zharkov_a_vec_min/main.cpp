// Copyright 2021 Zharkov Andrey
#include <gtest/gtest.h>
#include "./vec_min.h"
#include <gtest-mpi-listener.hpp>


TEST(Parallel_Operations_MPI, Test_Min_1) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<int> global_vec;
    const int count_size_vector = 120;

    if (rank == 0) {
        global_vec = getRandomVector(count_size_vector);
    }

    int global_min;
    global_min = getParallelOperations(global_vec, count_size_vector);

    if (rank == 0) {
        int reference_max = getSequentialOperations(global_vec);
        ASSERT_EQ(reference_max, global_min);
    }
}

TEST(Parallel_Operations_MPI, Test_Min_2) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<int> global_vec;
    const int count_size_vector = 240;

    if (rank == 0) {
        global_vec = getRandomVector(count_size_vector);
    }

    int global_min;
    global_min = getParallelOperations(global_vec, count_size_vector);

    if (rank == 0) {
        int reference_max = getSequentialOperations(global_vec);
        ASSERT_EQ(reference_max, global_min);
    }
}

TEST(Parallel_Operations_MPI, Test_Min_3) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<int> global_vec;
    const int count_size_vector = 1024;

    if (rank == 0) {
        global_vec = getRandomVector(count_size_vector);
    }

    int global_min;
    global_min = getParallelOperations(global_vec, count_size_vector);

    if (rank == 0) {
        int reference_max = getSequentialOperations(global_vec);
        ASSERT_EQ(reference_max, global_min);
    }
}

TEST(Parallel_Operations_MPI, Test_Min_4) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<int> global_vec;
    const int count_size_vector = 10;

    if (rank == 0) {
        global_vec = getRandomVector(count_size_vector);
    }

    int global_min;
    global_min = getParallelOperations(global_vec, count_size_vector);

    if (rank == 0) {
        int reference_max = getSequentialOperations(global_vec);
        ASSERT_EQ(reference_max, global_min);
    }
}

TEST(Parallel_Operations_MPI, Test_Min_5) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::vector<int> global_vec;
    const int count_size_vector = 790;

    if (rank == 0) {
        global_vec = getRandomVector(count_size_vector);
    }

    int global_min;
    global_min = getParallelOperations(global_vec, count_size_vector);

    if (rank == 0) {
        int reference_max = getSequentialOperations(global_vec);
        ASSERT_EQ(reference_max, global_min);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    MPI_Init(&argc, &argv);

    ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();

    listeners.Release(listeners.default_result_printer());
    listeners.Release(listeners.default_xml_generator());

    listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
    return RUN_ALL_TESTS();
}