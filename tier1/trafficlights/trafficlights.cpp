#include <iostream>
#include <string>

void digitalWrite(int in, int val)
{
  std::cout << "write " << in << ", " << val << "\n";
}

void pinMode(int in, int val)
{
  // std::cout << "pin mode " << in << ", " << val << "\n";
}

// O valor de a no led vermelho (saída 13)
// O valor de b no led amarelo (saída 12)
// O valor da saída da ULA  no led verde (saída 11)
// O valor de vai1 no led azul (saída 10)

void process(char instruction[])
{
  auto a = instruction[0] - 48;
  auto b = instruction[1] - 48;
  auto op = instruction[2] - 48;

  std::string h = "aaa";

  auto p = h[0];

  pinMode(13, 1);
  pinMode(12, 1);

  switch (op)
  {
  case 0:
    digitalWrite(11, a && b);
    digitalWrite(10, 0);
    break;

  case 1:
    digitalWrite(11, a || b);
    digitalWrite(10, 0);
    break;

  case 2:
    digitalWrite(11, !a);
    digitalWrite(10, 0);
    break;

  case 3:
    auto sum = a + b;

    if (sum == 0)
    {
      digitalWrite(11, 0);
      digitalWrite(10, 0);
    }
    else if (sum == 1)
    {
      digitalWrite(11, 1);
      digitalWrite(10, 0);
    }
    else
    {
      digitalWrite(11, 0);
      digitalWrite(10, 1);
    }

    break;
  }

  std::cout << "\n\n";
}

int main(int argc, char const *argv[])
{
  std::cout << "and\n";

  char and0[] = {'0', '0', '0'};
  process(and0);

  char and1[] = {'0', '1', '0'};
  process(and1);

  char and2[] = {'1', '0', '0'};
  process(and2);

  char and3[] = {'1', '1', '0'};
  process(and3);

  std::cout << "or\n";

  char or0[] = {'0', '0', '1'};
  process(or0);

  char or1[] = {'0', '1', '1'};
  process(or1);

  char or2[] = {'1', '0', '1'};
  process(or2);

  char or3[] = {'1', '1', '1'};
  process(or3);

  std::cout << "not\n";

  char not0[] = {'0', '0', '2'};
  process(not0);

  char not1[] = {'0', '1', '2'};
  process(not1);

  char not2[] = {'1', '0', '2'};
  process(not2);

  char not3[] = {'1', '1', '2'};
  process(not3);

  std::cout << "sum\n";

  char sum0[] = {'0', '0', '3'};
  process(sum0);

  char sum1[] = {'0', '1', '3'};
  process(sum1);

  char sum2[] = {'1', '0', '3'};
  process(sum2);

  char sum3[] = {'1', '1', '3'};
  process(sum3);

  return 0;
}
