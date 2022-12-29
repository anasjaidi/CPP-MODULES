# include <iostream>

struct Data
{
  int i;
};


uintptr_t serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

int main(void)
{
  Data d;
  d.i = 12;
  uintptr_t t = serialize(&d);
  Data *ptr = deserialize(t);
  std::cout << ptr->i <<std::endl;
  return 0;
}
