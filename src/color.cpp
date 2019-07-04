#include "color.hh"


Color other_team(Color c)
{
if (c == Color::RED)
return Color::BLUE;
return Color::RED;
}

std::string print_color(Color c)
{
switch(c)
{
case Color::BLUE:
return "Ce mot est BLEU.";
case Color::RED:
return "Ce mot est ROUGE.";
case Color::NEUTRAL:
return "Ce mot est NEUTRE.";
case Color::BLACK:
return "Ce mot est NOIR. Pas de chance :/";
case Color::FLIPPED:
return "Ce mot a déjà été deviné.";
default:
return "NOT IMPLEMENTED";
}
}