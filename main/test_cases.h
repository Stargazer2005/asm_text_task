#include <string>
#include <vector>

using PropertyUnitTest = std::pair<std::string, bool>;

using RuleUnitTest = std::pair<std::string, std::string>;

std::vector<PropertyUnitTest> property_tests{
    {"", true},
    {"a", true},
    {"A", true},
    {"z", true},
    {"Z", true},
    {"\\\"", false},
    {"arjk402-1l5,cvFD.,", false},
    {"arjk402-1l5,cvFD", false},
    {"aA", true},
    {"zZ", true},
    {"AQ", true},
    {"A1", true},
    {"AAAAAAAAAAAAAAAAAA", true},
    {"ACDEFGHIJKLMNOPAAB", true},
    {"#{}()<>,`__../\\|\"'", false},
    {"A#{}()<>,`../\\|\"'A", false},
    {"a#{}()<>,`../\\|\"'A", false},
    {"'A'", false},
    {"'A'B", false},
    {"qDCBABCDA", true},
};

std::vector<RuleUnitTest> rule1_tests{
    {"arjk402-1l5,cvFD.,", "arjkd0b-ale,cvFD.,"},
    {">|R_]XYp44{Wz_Pd", ">|R_]XYpdd{Wz_Pd"},
    {"}\\1Y~\\xd3dH1fqV>", "}\\aY~\\xdcdHafqV>"},
    {"K~DW88qtC1}>QSPw", "K~DWhhqtCa}>QSPw"},
    {"b;RMeUz>\\7Yya3_~", "b;RMeUz>\\gYyac_~"},
    {"{M8ldiFqD2Fdro57", "{MhldiFqDbFdroeg"},
    {"mPxhRE^2eRSRx`Pd", "mPxhRE^beRSRx`Pd"},
    {"sYWvihqv|YdqLuPW", "sYWvihqv|YdqLuPW"},
    {"<k\\h1YslwU\\4kX8<", "<k\\haYslwU\\dkXh<"},
    {"H6@\\vP;j?O[@;x?Y", "Hf@\\vP;j?O[@;x?Y"},
    {"}o@<L7N6?JNXzV5z", "}o@<LgNf?JNXzVez"},
    {">89mnNpr\\83DGgpx", ">himnNpr\\hcDGgpx"},
    {"ec<p>G7bFr1@iL[Y", "ec<p>GgbFra@iL[Y"},
    {"n`Miosi\\@V\\{wbrl", "n`Miosi\\@V\\{wbrl"},
    {"nwb4}96vk53l1:gN", "nwbd}ifvkecla:gN"},
    {"3`tQ}^KD;MKcgLw{", "c`tQ}^KD;MKcgLw{"},
    {"oRa<zPemC9G|=9:m", "oRa<zPemCiG|=i:m"},
    {"oUHeNNtqtVg8:d>v", "oUHeNNtqtVgh:d>v"},
    {"rA=:~yfj6Us:vZ^C", "rA=:~yfjfUs:vZ^C"},
    {"OtDRu}^uMLVP@}_b", "OtDRu}^uMLVP@}_b"},
    {"35tUbr<P8V}OYcWj", "cetUbr<PhV}OYcWj"},
};

std::vector<RuleUnitTest> rule2_tests{
    {"1f?Ahh;k44j:jkBh", "1f?Ah;k4j:jkBh"},
    {"B>4T>@8@h2>9U??2", "B>4T>@8@h2>9U?2"},
    {"?hjih2UjU=h<3kf:", "?hjih2UjU=h<3kf:"},
    {"j;924?@>UiUAh99f", "j;924?@>UiUAh9f"},
    {"A9T>1B41g;;8gU;@", "A9T>1B41g;8gU;@"},
    {"U=g3fUT<B=h22?jh", "U=g3fUT<B=h2?jh"},
    {"hB2g?Ti?h;j=fj?<", "hB2g?Ti?h;j=fj?<"},
    {"38f49B=B;j9j:kUT", "38f49B=B;j9j:kUT"},
    {"<h12k@h9T19k:2<4", "<h12k@h9T19k:2<4"},
    {"@<>?kghfU??A<;A;", "@<>?kghfU?A<;A;"},
    {"B@i;?T>@;k3gBkkU", "B@i;?T>@;k3gBkU"},
    {"@?>81f==4?BBjU2U", "@?>81f=4?BjU2U"},
    {"h>8>?2>jhi<f@h?1", "h>8>?2>jhi<f@h?1"},
    {"T2?94Th8Ak12@?4g", "T2?94Th8Ak12@?4g"},
    {"8jAi;13A;:?A;k2A", "8jAi;13A;:?A;k2A"},
};
