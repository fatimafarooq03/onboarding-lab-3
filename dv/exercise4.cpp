#include <VExercise4.h>
#include <cstdint> 


uint8_t selector(uint8_t sel, bool cs,  uint8_t alpha,  uint8_t beta,  uint8_t gamma)
{
  if (cs == 0)
  {
    return 0; 
  }

  else if (cs == 1)
  {
    if (sel == 0)
    {
      return alpha; 
    }

    else if (sel == 1)
    {
      return beta;
    }

    else if (sel == 2)
    {
      return gamma; 
    }

    else if (sel == 3)
    {
      return (alpha & (beta | gamma)); 
    }
  }

}

int main() {
  VExercise4 model;

  bool cs; 
  uint8_t sel;
  uint8_t alpha; 
  uint8_t beta;
  uint8_t gamma; 

// testing for when cs = 0 case

cs = 0; // cs is 0

// setting cs as 0
model.cs = 0; 

// now check for all values of sel 

for (int i = 0;i < 4; i++)
{
  sel = i; 
  
  // random input values:
  alpha = rand() % 255;
  beta = rand() % 255;
  gamma = rand() % 255;

  model.sel = sel; 
  model.alpha = alpha; 
  model.beta = beta;
  model.gamma = gamma; 

  model.eval(); 

  if (model.out != selector(sel,cs,alpha,beta,gamma))
  {
    return -1; 
  }
}

// testing for cs = 1 case

cs = 1; // cs is 1

// setting cs as 1
model.cs = 1; 

// now check for all values of sel 
for (int i = 0;i < 4; i++)
{
  sel = i; 
  
  // random input values:
  alpha = rand() % 255;
  beta = rand() % 255;
  gamma = rand() % 255;

  model.sel = sel; 
  model.alpha = alpha; 
  model.beta = beta;
  model.gamma = gamma; 

  model.eval(); 

  if (model.out != selector(sel,cs,alpha,beta,gamma))
  {
    return 1; 
  }
}

return 0; 

}
