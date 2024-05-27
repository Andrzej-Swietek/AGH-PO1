#pragma once
#include "FSElement.h"
#include "SoftLink.h"

/**
 * @brief Helper Method Allowing to add new FSElement to directory 
 * @param[in] element pointer to element that is to be added
 * @return FSElement pointer
*/
FSElement* add(FSElement* element, std::string name ){
	// rename the link to name?

	// element->SetName(name);
	return static_cast<FSElement*>(element);
}
