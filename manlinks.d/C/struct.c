#include <stdio.h>

       /* Typedefs and Definitions */
       typedef struct address address_t;
       typedef struct person person_t;

       struct address {
           const char *street;
           const char *postcode;
       };

       struct person {
           const char *name;
           struct address address;
       };

void initializations(void)
{
       /* Initialization */
       struct address home = { "12 Main St", "10000" };

       person_t Mama = { "Mama Bear", { "12 main St", "10000" }};

       person_t Papa = {
           .name = "Papa Bear",
           .address = { "12 Main Street", "10000" }
       };

       person_t Sister = {
           .name = "Sister Bear",
           .address.postcode = "10000"
       };

       person_t Brother = {
           .name = "Brother Bear",
           .address = Mama.address
       };

       /* Compound Literal (cast to struct) */
       address_t neighbor = (address_t){ "100 Main St", "10000" };
       address_t *favorite = &(address_t){ "100 Main St", "10000" };
       person_t Baby = (person_t){
           .name = "Baby Bear",
           .address = (address_t){
               .street = "100 Main St",
               .postcode = "10000"
           }
       };
}

void assignments(void)
{
       /* Assignments */
       person_t friend;
       friend.name = "Tammy";
       friend.address = (struct address){ "24 Elm St", "10000" };
}


#ifdef STRUCT_MAIN
typedef struct person_plus person_plus_t;
struct person_plus {
   struct person base;
   int           age;
   const char    *profession;
};

void show_person(const person_t *person)
{
   printf("name:        %s\n"
          "address:\n"
          "   street:   %s\n"
          "   postcode: %s\n",
          person->name, person->address.street, person->address.postcode);
}

void show_person_plus(const person_plus_t *person)
{
   show_person((person_t*)person);
   printf("age:         %d\n"
          "profession:  %s\n",
          person->age, person->profession);
}

void demo_person_plus(void)
{
   person_plus_t per = (person_plus_t){"Joe", {"45 Skid Row", "02020"}, 29, "rabble-rouser"};
   person_t *dude = (person_t*)&per;

   show_person_plus((person_plus_t*)dude);
}

void demo_named_fields(void)
{
   person_plus_t per = (person_plus_t){
      .base.name = "Roger",
      .age = 35,
      .profession = "director"
   };

   show_person_plus(&per);
}



int main(int argc, const char **argv)
{
   initializations();
   assignments();

   demo_person_plus();
   demo_named_fields();

   return 0;
}



#endif

/* Local Variables:        */
/* compile-command: " gcc \*/
/* -DSTRUCT_MAIN          \*/
/* -ggdb                  \*/
/* -o struct struct.c"    \*/
/* End:                    */
