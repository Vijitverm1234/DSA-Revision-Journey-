### Querie 1
query to get total sales amount for each month 

```
SELECT Month(sales_date),month,sum(amount) as tot_sal from sales where Year(sales_date)=2023 group by Month(sales_month) ;

```
### Querie 2
customer(cus_id,cus_name,city) 


orders(order_id,cus_id,orderDate,orderAmount)
```
select a.cus_name from customer a join orders b on a.cus_id=b.cus_id where orderdate>'2023-01-01';

```
