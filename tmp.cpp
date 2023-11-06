#include <stack>



fixed::fixed() {}

fixed::fixed(double const &d)
{
	double tmp = d * (1ULL << decimal_bits);
	data = (t_ll)tmp;
}
fixed::fixed(float const &f)
{
	double tmp = (double)f * (1ULL << decimal_bits);
	data = (t_ll)tmp;
}
fixed::fixed(int const	&i) {
	this->data = (t_ll)i << decimal_bits;
}
fixed fixed::operator+(fixed const &f)
{
	fixed ret;

	ret.data = this->data + f.data;
	return (ret);
}
fixed fixed::operator-(fixed const &f)
{
	fixed ret;

	ret.data = this->data - f.data;
	return (ret);
}
fixed fixed::operator*(fixed const &op)
{
	t_ull a_up = (this->data >> 32);
	t_ull b_up = (op.data >> 32);
	t_ull a_down = ((t_ull)this->data & 0xffffffff);
	t_ull b_down = ((t_ull)op.data & 0xffffffff);
	fixed ret;

	ret.data = ((a_up * b_up) << (64 - decimal_bits)) + ((a_up * b_down + a_down * b_up) << (32 - decimal_bits)) + ((a_down * b_down) >> decimal_bits);
	return (ret);
}
fixed fixed::operator/(fixed const &op)
{
	t_ll up = this->data;
	t_ll down = (this->data % op.data) << decimal_bits;
	fixed ret;

	ret.data = ((up / op.data) << decimal_bits) + (down / op.data);

	return (ret);
}

fixed	fixed::operator%(fixed const &op) {
	fixed	ret;

	ret.data = (this->data % op.data);
	return (ret);
}
fixed	&fixed::operator=(float const &f) {
	double tmp = (double)f * (1ULL << decimal_bits);
	this->data = (t_ll)tmp;
	return (*this);
}
fixed	&fixed::operator=(int const &i) {
	this->data = (t_ll)i << decimal_bits;
	return (*this);
}
fixed	&fixed::operator=(t_ll const &i) {
	this->data = (t_ll)i << decimal_bits;
	return (*this);
}
fixed	fixed::operator-() {
	fixed	ret;

	ret.data = -this->data;
	return (ret);
}
fixed::operator float() const
{
	double tmp = (double)this->data;
	tmp /= (1LL << decimal_bits);

	return (tmp);
}

fixed::operator double() const
{
	double tmp = (double)this->data;
	tmp /= (1LL << decimal_bits);

	return (tmp);
}

fixed::operator long long() const
{
	return ((this->data >> decimal_bits) + (this->data >> 63 & 1));
}

fixed	sin(fixed rad) {
	fixed	x = (rad % 3.141592f);
	fixed	x_squared = x * x;
	fixed	ret = 0;

	ret = x_squared / (11 * 10) - 1;
	ret = ret * x_squared / (9 * 8) + 1;
	ret = ret * x_squared / (7 * 6) - 1;
	ret = ret * x_squared / (5 * 4) + 1;
	ret = ret * x_squared / (3 * 2) - 1;
	ret = ret * -x;

	return (ret);
}

fixed	cos(fixed rad) {
	fixed	x = (rad % 3.141592f);
	fixed	x_squared = x * x;
	fixed	ret = 0;

	ret = x_squared / (10 * 9) - 1;
	ret = ret * x_squared / (8 * 7) + 1;
	ret = ret * x_squared / (6 * 5) - 1;
	ret = ret * x_squared / (4 * 3) + 1;
	ret = ret * x_squared / (2 * 1) - 1;

	return (-ret);
}

std::ostream	&operator<<(std::ostream &os, fixed	&op) {
	static const char	*m[] = {
		"50000000000000000000000000000000",
		"25000000000000000000000000000000",
		"12500000000000000000000000000000",
		"06250000000000000000000000000000",
		"03125000000000000000000000000000",
		"01562500000000000000000000000000",
		"00781250000000000000000000000000",
		"00390625000000000000000000000000",
		"00195312500000000000000000000000",
		"00097656250000000000000000000000",
		"00048828125000000000000000000000",
		"00024414062500000000000000000000",
		"00012207031250000000000000000000",
		"00006103515625000000000000000000",
		"00003051757812500000000000000000",
		"00001525878906250000000000000000",
		"00000762939453125000000000000000",
		"00000381469726562500000000000000",
		"00000190734863281250000000000000",
		"00000095367431640625000000000000",
		"00000047683715820312500000000000",
		"00000023841857910156250000000000",
		"00000011920928955078125000000000",
		"00000005960464477539062500000000",
		"00000002980232238769531250000000",
		"00000001490116119384765625000000",
		"00000000745058059692372812500000",
		"00000000372529029846191406250000",
		"00000000186264514923095703125000",
		"00000000093132257461547851562500",
		"00000000046566128730773925781250",
		"00000000023283064365386962890625",
	};
	int				sum = 0;
	std::stack<int>	digit;
	int const		fractional = std::abs(op.data) & ((1 << fixed::decimal_bits) - 1);

	os << (long long)op << ".";

	for (int i = 31; i >= 0; i--)
	{
		for (int j = fixed::decimal_bits - 1; j >= 0; j--)
		{
			sum += (m[j][i] - '0') * ((fractional >> (fixed::decimal_bits - j - 1)) & 1);
		}
		digit.push(sum % 10);
		sum /= 10;
	}
	for (int i = 0; i < fixed::decimal_bits; i++) {
		os << digit.top();
		digit.pop();
	}
	return (os);
}