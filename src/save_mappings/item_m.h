typedef struct {
    unsigned int value;
    const char* name;
} ItemMapping;

extern ItemMapping itemMap[];
extern const int item_m_SIZE;

char* getItemName(unsigned int searchId);