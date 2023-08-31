#include <string.h>
#include <unistd.h>

class N {
public:
	void *undefined;
	char annotation[0x64];
	int num;

	N(int param_1) {
		this->num = param_1;
	}
	void setAnnotation(char *param_1) {
		size_t len;

		len = strlen(param_1);
		memcpy((void *)this->annotation, param_1, len);
	}
	int operator+(N *param_1) const {
		return this->num + param_1->num;
	}
	int operator-(N *param_1) {
		return this->num - param_1->num;
	}
};

int main(int ac, char **av)
{
  N *n_first;
  N *n_second;

  if (ac < 2) {
    _exit(1);
  }
  n_first = new N(5);
  n_second = new N(6);

  n_first->setAnnotation(av[1]);

  n_second->operator+(n_first);
  return 0;
}
