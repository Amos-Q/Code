#pragma once
#include <vector>

namespace bit
{
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bits.resize(N/32+1, 0); // 也有问题，思考一下问题在哪？
			_num = 0;
		}

		void set(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置在第几个整形
			size_t pos = x % 32;   // 算出x在整形的第几个位

			_bits[index] |= (1 << pos); // 第pos个位置成1

			++_num;
		}

		void reset(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置在第几个整形
			size_t pos = x % 32;   // 算出x在整形的第几个位

			_bits[index] &= ~(1 << pos); // 第pos个位置成0

			--_num;
		}

		// 判断x在不在(也就是说x映射的位知否为1)
		bool test(size_t x)
		{
			size_t index = x / 32; // 算出映射的位置在第几个整形
			size_t pos = x % 32;   // 算出x在整形的第几个位

			return _bits[index] & (1 << pos);
		}
	private:
		//int* _bits;
		std::vector<int> _bits;
		size_t _num;  // 映射存储的多少个数据
	};

	void test_bitset()
	{
		/*bitset bs(100);
		bs.set(99);
		bs.set(98);
		bs.set(97);
		bs.set(5);
		bs.reset(98);

		for (size_t i = 0; i < 100; ++i)
		{
			printf("[%d]:%d\n", i, bs.test(i));
		}*/

		bitset bs(-1);
		//bitset bs(pow());
		//bitset bs(0xffffffff);

	}
}