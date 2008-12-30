#ifndef _MARKETAGENT_H
#define _MARKETAGENT_H

#include "libs.h"
#include "ShipType.h"

class MarketAgent {
public:
	MarketAgent(): m_money(0) {}
	void SetMoney(Sint64 m) { m_money = m; }
	Sint64 GetMoney() { return m_money; }
	bool Pay(MarketAgent *b, Sint64 amount);
	bool SellItemTo(MarketAgent *other, Equip::Type t);
	virtual int GetPrice(Equip::Type t) const = 0;
	virtual bool CanBuy(Equip::Type t) const = 0;
	virtual bool CanSell(Equip::Type t) const = 0;
protected:
	virtual void Bought(Equip::Type t) = 0;
	virtual void Sold(Equip::Type t) = 0;
	void Load();
	void Save() const;
private:
	Sint64 m_money;
};

#endif /* _MARKETAGENT_H */