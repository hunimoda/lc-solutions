  std::cout << "# Starting timer..." << std::endl;
  auto start = high_resolution_clock::now();
  for (uint32_t i = 0; i <= 1'000'000'000; i++) {
    if (i % 10'000'000 == 0)
      std::cout << i / 10'000'000 << "%..." << std::endl;
    solution.ReverseBits(i);
  }
  std::cout << "# Timer END!" << std::endl;
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);
  std::cout << "# " << duration.count() << " [us] consumed" << std::endl;