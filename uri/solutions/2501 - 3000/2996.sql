select b.year, a.name as sender, c.name as receiver from packages b
inner join users a
on a.id = b.id_user_sender
inner join users c
on c.id = b.id_user_receiver
where (color ilike 'blue' or year = 2015) and (
	(a.address not ilike 'Taiwan') and (c.address not ilike 'Taiwan')
) order by b.year desc;
