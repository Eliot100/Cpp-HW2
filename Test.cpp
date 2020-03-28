
#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <string>
#include <iostream>

/*
Letters that can be switchd:
	v, w
	b, f, p
	g, j
	c, k, q
	s, z
	d, t
	o, u
	i, y
	
And all letter can be capital and small.

* @author Eli, Ron and Tal

*
*/
TEST_CASE("famous quotes") {
	string text0 = "Very good famous quotes"; 
	string parmotaitionOf_Very[5] = { "Wery","wERI","Veri","veri","veRY"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text0, parmotaitionOf_Very[i]) == std::string("Very"));
    
	string parmotaitionOf_good[5] = { "Gout","gOUT","JooD","juud","gOOd"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text0, parmotaitionOf_good[i]) == std::string("good"));
    
	string parmotaitionOf_famous[6] = { "bamuus","BamooS","FAMOUs","famouz","PamuuZ","pamuoz"};
	for (int i = 0; i < 6; i++)
		CHECK(phonetic::find(text0, parmotaitionOf_famous[i]) == std::string("famous"));
    
	string parmotaitionOf_quotes[10] = { "qootes","COODEZ","kuuTeS","CUotez","cuotez", "Koodes","Quotez","cuotes","qoutes","quotes"};
	for (int i = 0; i < 10; i++)
		CHECK(phonetic::find(text0, parmotaitionOf_quotes[i]) == std::string("quotes"));
	
    string text1 = "The order of the phoenix"; 
	string parmotaitionOf_The[5] = { "the", "THE", "thE", "dhe", "Dhe"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text1, parmotaitionOf_The[i]) == std::string("The"));
	
	string parmotaitionOf_order[5] = { "order", "Order", "urder", "orter", "urtER"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text1, parmotaitionOf_order[i]) == std::string("order"));
    
	string parmotaitionOf_of[10] = { "of", "OF", "uF", "Ub", "UB", "ob", "OB", "op", "OP", "up"};
	for (int i = 0; i < 10; i++)
		CHECK(phonetic::find(text1, parmotaitionOf_of[i]) == std::string("of"));
    
	string parmotaitionOf_phoenix[5] = { "phoenix", "PhoenYx", "Fhuenix","bHOENIX", "bhuenyx"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text1, parmotaitionOf_phoenix[i]) == std::string("phoenix"));
    
	string text2 = "To be or not to be";
	string parmotaitionOf_To[10] = { "To", "TO", "Tu","TU", "to", "tO", "tu","tU", "Do","dO"};
	for (int i = 0; i < 10; i++)
		CHECK(phonetic::find(text2, parmotaitionOf_To[i]) == std::string("To"));
    
	string parmotaitionOf_be[5] = { "be", "BE", "Fe", "fe", "PE"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text2, parmotaitionOf_be[i]) == std::string("be"));
    
	string parmotaitionOf_or[5] = { "or", "OR", "ur", "Ur", "uR"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text2, parmotaitionOf_or[i]) == std::string("or"));
    
	string parmotaitionOf_not[5] = { "Not", "nUt", "nud", "NUT", "nuD"};
	for (int i = 0; i < 5; i++)
		CHECK(phonetic::find(text2, parmotaitionOf_or[i]) == std::string("not"));
    
    string text3 = "I want to be the king ";
    string parmotaitionOf_King[10]= {"qing", "Qing", "cing","Cing", "KYNg", "KINJ","kinj","ginj","KinJ", "KiNj" };
   for (int i = 0; i < 10; i++)
    CHECK(phonetic::find(text3, parmotaitionOf_King[i]) == std::string("king"));

   string parmotaitionOf_want[5]= {"the", "wanr", "WANa","wsnt","qant"};
    for (int i = 0; i < 5; i++)
        try
        {
            CHECK(phonetic::find(text3, parmotaitionOf_want[i]) == std::string("want"));
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
    string text4 = "Students are the best";
    string parmotaitionOf_Students[10]= {"studenett", "seuyde", "Studenent","ssddff", "KYNg", "","4","","a a", "Student s" };
    for (int i = 0; i < 10; i++)
        try {
            CHECK(phonetic::find(text4, parmotaitionOf_Students[i]) == std::string("Students"));
        }
    catch(exception& e)
    {
        cout << e.what() << '\n';
    }
}

