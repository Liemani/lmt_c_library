#include "t_lmt_sequence_element.h"

void	lmt_sequence_element_apply(t_lmt_sequence_element *element, t_lmt_sequence_appliance appliance)
{
	appliance(element->content);
}
