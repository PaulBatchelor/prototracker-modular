#pragma once

#include "Editor.h"

struct EditorState;
struct Renderer;
struct SDL_Rect;
struct TextEditor;
struct Label;
struct MessageBox;

#include <vector>
#include <string>

class GenericSelector: public Editor
{
	static const int titleSize = 256;
	int mId;
	char mTitle[titleSize];
	Label *mLabel;
	int mSelectedItem;

protected:
	struct Item {
	};

	void selectItem(int index);
	const Item& getSelectedItem() const;

	virtual void renderItem(Renderer& renderer, const SDL_Rect& area, const Item& item, bool isSelected) = 0;
	virtual void accept(bool isFinal = false) = 0;
	virtual void reject(bool isFinal = false) = 0;
	virtual void onSelectItem(const Item& item) = 0;

	void addItem(Item* newItem);
	void clearItems();
	void sortItems(bool (*comparator)(const Item* a, const Item* b));

private:
	std::vector<Item*> mItems;

public:
	GenericSelector(EditorState& editorState);
	virtual ~GenericSelector();

	/* Set dialog id (freely set and used by the Editor that creates the dialog)
	 */
	void setId(int id);
	int getId() const;

	/* Set dialog title
	 */
	void setTitle(const char *title);

	virtual bool onEvent(SDL_Event& event);
	virtual void onDraw(Renderer& renderer, const SDL_Rect& area);
};
