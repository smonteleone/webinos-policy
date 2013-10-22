#include "core/policymanager/PolicyManager.h"
#include "debug.h"

PolicyManager* pminst;
string policyFileName;

int main ()
{
	
	map<string, vector<string>*> * pip = new map<string, vector<string>*>();
    (*pip)["http://webinos.org/subject/id/PZ-Owner"] = new vector<string>();
    (*pip)["http://webinos.org/subject/id/PZ-Owner"]->push_back("salvatoremonteleone@130.192.1.123");
    (*pip)["http://webinos.org/subject/id/known"] = new vector<string>();
    (*pip)["http://webinos.org/subject/id/known"]->push_back("friend1");
    (*pip)["http://webinos.org/subject/id/known"]->push_back("friend2");
    (*pip)["http://webinos.org/subject/id/known"]->push_back("friend3");

    pminst = new PolicyManager("./testpolicy.xml", pip);

    map<string, vector<string>*> * subject_attrs = new map<string, vector<string>*>();
    (*subject_attrs)["user-id"] = new vector<string>();
    (*subject_attrs)["user-id"]->push_back("1215N");

    (*subject_attrs)["id"] = new vector<string>();

    map<string, vector<string>*> * resource_attrs = new map<string, vector<string>*>();
    (*resource_attrs)["api-feature"] = new vector<string>();
    (*resource_attrs)["api-feature"]->push_back("http://webinos.org/api/discovery");

    (*resource_attrs)["service-id"] = new vector<string>();
    (*resource_attrs)["device-cap"] = new vector<string>();
    (*resource_attrs)["param:feature"] = new vector<string>();

    vector<bool> purpose = vector<bool>(arraysize(ontology_vector), true);

    obligations obs = vector<obligation>();
/*
    obligations obs = 0;
    obligation ob = obligation();
    map<string, string> action;
    map<string, string> trigger;
    vector< map<string, string> > triggers;
*/
	map<string, string> * environment_attrs = new map<string, string>();
	(*environment_attrs)["profile"] = "";

    Request* myReq = new Request(*subject_attrs, *resource_attrs, purpose, obs, *environment_attrs);
    Effect myEff = pminst->checkRequest(myReq);

    cout << "Result is " << myEff << endl;

    return 0;
}
