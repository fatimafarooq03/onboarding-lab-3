#include <VExercise1.h>
#include <cstdint>

 // VExercise1 model;
 

bool test(uint8_t op)
{
  VExercise1 model;
  model.op = op;
  model.a = 0;
  model.b = 0;
  while(++model.b)
  {
    while(++model.a)
    {
       model.eval();
       uint8_t result; 
       if (op == 0)
       {
        result = model.a^model.b; 
       }

       else if (op==1)
       {
        result = model.a << model.b; 
       }

       else if (op==2)
       {
        result = model.a % model.b; 
       }

       else if (op==3)
       {
        result = ~(model.a & model.b); 
       }

       else
       {
        return false;
       }
      
      if (model.out != result)
      {
        return false;
      }
    }
  }


  return true; 

}

int main()
{

  if (!(test(0)))
  {
    return 1; 
  }

  else if (!(test(1)))
  {
    return 1; 
  }

  else if (!(test(2)))
  {
    return 1; 
  }

  else if (!(test(3)))
  {
    return 1; 
  }

return 0; 

};

