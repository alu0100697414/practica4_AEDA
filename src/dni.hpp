// Clase dni.

class DNI {

private:

  unsigned int dni_;

public:

  DNI(void);
  DNI(int dato);
  ~DNI(void);

  void set_dni(int dato);
  int get_dni(void);
};
