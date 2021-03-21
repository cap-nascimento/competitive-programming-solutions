--- Anderson Vieira's solution

CREATE TABLE value_table(
	amount int not null
);

INSERT INTO value_table(amount) VALUES(4);
INSERT INTO value_table(amount) VALUES(4);
INSERT INTO value_table(amount) VALUES(4);
INSERT INTO value_table(amount) VALUES(4);
INSERT INTO value_table(amount) VALUES(1);
INSERT INTO value_table(amount) VALUES(1);
INSERT INTO value_table(amount) VALUES(2);

select amount, count(amount) as f from value_table
group by amount order by count(amount) desc;

select amount as most_frequent_value
from value_table
group by amount
having count(*) >= ALL (select count(*) from value_table group by amount)
order by amount asc;