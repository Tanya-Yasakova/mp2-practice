#ifndef _TABRECORD_H
#define _TABRECORD_H
#include <iostream>
#include <iomanip> //�������������� ����� � ������
using namespace std;

template <typename TKey, typename TData>
class TabRecord {
public:
	TKey key;
	TData* data;
	TabRecord() : key(), data(nullptr) {}
	TabRecord(const TKey& _key, TData* _data);
	TabRecord(const TabRecord<TKey, TData>& record);
	~TabRecord();
	TKey GetKey() const;
	TData* GetData() const;
	const TabRecord<TKey, TData>& operator=(const TabRecord<TKey, TData>& record);
	bool operator==(const TabRecord<TKey, TData>& record) const;
	bool operator!=(const TabRecord<TKey, TData>& record) const;
	friend ostream& operator<<(std::ostream& out, const TabRecord < TKey, TData>& record)
	{
		out << left << setw(10) << record.GetKey() << " | " << left << setw(10) << *record.GetData();
		return out;
	}
};

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord(const TKey& _key, TData* _data) : key(_key) {
	data = new TData(*_data);
}

template <typename TKey, typename TData>
TabRecord<TKey, TData>::TabRecord(const TabRecord<TKey, TData>& record) : key(record.key) {
	data = new TData(*record.data);
}

template<typename TKey, typename TData>
TabRecord<TKey, TData>::~TabRecord() {
	delete data;
}

template <typename TKey, typename TData>
TKey TabRecord<TKey, TData>::GetKey() const {
	return key;
}

template <typename TKey, typename TData>
TData* TabRecord<TKey, TData>::GetData() const {
	return data;
}

template<typename TKey, typename TData>
const TabRecord<TKey, TData>& TabRecord<TKey, TData>::operator=(const TabRecord& record) {
	if (this == &record) {
		return *this;
	}
	key = record.key;
	data = new TData(*record.data);
	return *this;
}

template<typename TKey, typename TData>
bool TabRecord<TKey, TData>::operator==(const TabRecord<TKey, TData>& record) const {
	return (key == record.GetKey() && *data == *record.GetData());
}

template<typename TKey, typename TData>
bool TabRecord<TKey, TData>::operator!=(const TabRecord<TKey, TData>& record) const {
	return !(*this == record);
}

#endif 